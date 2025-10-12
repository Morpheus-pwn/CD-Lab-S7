# CD-Lab-S7
# S7 Compiler Lab Experiments (KTU 2019 Scheme)

(See [Syllabus](https://drive.google.com/file/d/1Rioof9iXXxhx8r6v0KyUyEd0BAUTCSba/view))

## Experiments According to Rough Record Order

| **Sl. No.** |                        **Experiment**                        |
| :---------: | :----------------------------------------------------------: |
|      1      |      Implementation Of Lexical Analyzer Using Lex Tool       |
|      2      | Lex prg to display no. of lines,space,words and characters   |
|      3      |          Lex program to convert Substring abc -> ABC         |
|      4      |    Lex program to display number of vowels and consonants    |
|      5      |            YACC Program to detect valid idenifier            |
|      6      |          Lex program to implement simple calculator          |
|      7      |      YACC Program to detect valid arithmetic expression      |
|      8      |                 Simple calculator using YACC                 |
|      9      |            Program to implement first and follow             |
|     10      |          Lex program to Implement Pattern Matching           |
|     11      |           Program to implement Shift Reduce Parser           |
|     12      |        Program to implement Conversion of NFA to DFA         |
|     13      |        Program to implement Recursive Descent Parser         |
|     14      |                   Program to implement E-NFA                 |
|     15      |              Program to perform DFA minimization             |
|     16      |           Program to perform Constant Propagation            |

## Compiling and running programs

### C Programs

```
gcc program.c 
./a.out
```

### Lex Programs

```
lex main.l
gcc lex.yy.c 
./a.out
```

### YACC Programs

```
lex prog.l
yacc -d prog.y -W
gcc lex.yy.c y.tab.c -w
./a.out
```

## Common Troubleshooting

- Installation: For running Lex and YACC Programs in your computer you have to install `Flex` and `Bison` respectively in your operating system.

    - [GNU/Linux](https://anandgharu.wordpress.com/wp-content/uploads/2018/02/how-to-install-lex-yacc.pdf)

    - [Windows](https://thesvgway.wordpress.com/2013/10/09/how-to-compile-run-lex-yacc-programs-on-windows/)
    (Or Just use WSL or boot Gnu/Linux on your machine)
    - MAC (IDK 🤷)
- For YACC programs in newer versions of YACC and Bison compiler if `gcc lex.yy.c y.tab.c -w` returns an error like:
```
y.tab.c:1025:16: error: implicit declaration of function ‘yylex’ [-Wimplicit-function-declaration]
 1025 |       yychar = yylex ();
```

then simply edit .y file to include definition of that function in definition area (Within `%{ %}`)

From:

> ```
> %{
>  #include<stdio.h>
>  int valid=1;
> %}
>  ```

To:

>  ```
>  %{
>   #include<stdio.h>
>   int yylex();
>   int yyerror(); // if yyerror() also returns similar error
>   int valid=1;
>  %}
>  ```
