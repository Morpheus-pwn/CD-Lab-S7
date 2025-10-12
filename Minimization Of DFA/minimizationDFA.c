#include <stdio.h>
#include <stdlib.h>

#define MAX_STATES 20
#define MAX_SYMBOLS 10

int transition[MAX_STATES][MAX_SYMBOLS];
int isFinal[MAX_STATES];
int stateCount, symbolCount;
int reachable[MAX_STATES];

void dfs(int state) {
    if (reachable[state]) return;
    reachable[state] = 1;
    for (int i = 0; i < symbolCount; i++) {
        int next = transition[state][i];
        if (next != -1)
            dfs(next);
    }
}

void removeUnreachable() {
    for (int i = 0; i < stateCount; i++)
        reachable[i] = 0;

    dfs(0); // assuming 0 is the start state

    for (int i = 0; i < stateCount; i++) {
        if (!reachable[i]) {
            for (int j = 0; j < symbolCount; j++)
                transition[i][j] = -1;
        }
    }
}

int equivalent(int s1, int s2, int group[]) {
    if (isFinal[s1] != isFinal[s2]) return 0;
    for (int i = 0; i < symbolCount; i++) {
        int t1 = transition[s1][i];
        int t2 = transition[s2][i];
        if (t1 == -1 && t2 == -1) continue;
        if (t1 == -1 || t2 == -1) return 0;
        if (group[t1] != group[t2]) return 0;
    }
    return 1;
}

void minimizeDFA() {
    removeUnreachable();

    int group[MAX_STATES];
    int newGroup[MAX_STATES];
    int groupCount = 2; 

    for (int i = 0; i < stateCount; i++) {
        if (reachable[i] == 0) {
            group[i] = -1; 
        } else {
            group[i] = isFinal[i];
        }
    }

    int changed;
    do {
        changed = 0;
        int nextGroup = 0;
        int mapping[MAX_STATES];
        for (int i = 0; i < stateCount; i++) newGroup[i] = -1;

        for (int i = 0; i < stateCount; i++) {
            if (group[i] == -1) continue;
            if (newGroup[i] != -1) continue;
            newGroup[i] = nextGroup;
            for (int j = i + 1; j < stateCount; j++) {
                if (group[j] != -1 && equivalent(i, j, group)) {
                    newGroup[j] = nextGroup;
                }
            }
            nextGroup++;
        }

        for (int i = 0; i < stateCount; i++) {
            if (group[i] != newGroup[i]) changed = 1;
            group[i] = newGroup[i];
        }

        groupCount = 0;
        for (int i = 0; i < stateCount; i++)
            if (group[i] + 1 > groupCount)
                groupCount = group[i] + 1;

    } while (changed);

    printf("\nMinimized DFA:\n");
    printf("Total minimized states: %d\n", groupCount);
    for (int i = 0; i < groupCount; i++) {
        printf("State %d: ", i);
        for (int s = 0; s < symbolCount; s++) {
            int target = -1;
            for (int j = 0; j < stateCount; j++) {
                if (group[j] == i) {
                    int t = transition[j][s];
                    if (t != -1)
                        target = group[t];
                    break;
                }
            }
            if (target != -1)
                printf("On symbol %d -> State %d, ", s, target);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of states: ");
    scanf("%d", &stateCount);
    printf("Enter number of symbols: ");
    scanf("%d", &symbolCount);

    printf("Enter transition table:\n");
    for (int i = 0; i < stateCount; i++) {
        for (int j = 0; j < symbolCount; j++) {
            printf("Transition from state %d on symbol %d: ", i, j);
            scanf("%d", &transition[i][j]);
        }
    }

    for (int i = 0; i < stateCount; i++)
        isFinal[i] = 0;

    int numFinalStates;
    printf("Enter number of final states: ");
    scanf("%d", &numFinalStates);
    printf("Enter final states:\n");
    for (int i = 0; i < numFinalStates; i++) {
        int f;
        scanf("%d", &f);
        isFinal[f] = 1;
    }

    minimizeDFA();
    return 0;
}


