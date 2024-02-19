$${\color{lightgreen}Análise \space Léxica}$$
```diff
+ [OK] Verificação dos tokens para:
    # chr     (letra)
    # int     (número inteiro)
    # flt     (número flutuante)
    # dbl     (número double)
    # if      (condicional)
    # els     (condicional)
    # whl     (loop condicional)
    # for     (loop condicional)
    # lets_go (continue)
    # fnc     (função)
    # void    (tipo sem retorno)
    # rtn     (return)
    # brk     (break)
    # clss    (classe)
    # new     (instanciação de classe)
    # prnt    (print)
    # scn     (scanf)
    # pvt     (privado para a classe)
    # pub     (público para na classe)
    # main    (função principal)
    # import  (importação de classe)
    # //      (comentário de linha)
    # /* */   (comentário de bloco)
    # Outros Tokens: [+, -, *, /, ++, --, =, ==, !=, >, <, >=, <=, and, or, not, (, ), {, }, [, ], ;, ,, ., :, ", ', \n, \t, ]
    
+ [OK] Verificação de strings
+ [OK] Verificação de tabulação
+ [OK] Verificação de comentários
+ [OK] Verificação de quebra de linha
+ [OK] Verificação de espaços em branco
+ [OK] Verificação de palavras reservadas
+ [OK] Verificação de números, letras e símbolos
```
$${\color{lightgreen}Análise \space Sintática}$$
```diff
+ [OK] Verificação de loops
+ [OK] Verificação de operações
+ [OK] Verificação de condicionais
+ [OK] Verificação da função principal
+ [OK] Verificação de declaração de funções
+ [OK] Verificação de declaração de classes
+ [OK] Verificação de importação de classes
+ [OK] Verificação de declaração de variáveis
```
$${\color{lightgreen}Análise \space Semântica}$$
```diff
+ [OK] Verificação de variável já declarada
+ [OK] Verificação de classe utilizada sem importação
! [  ] Abstract Syntax Tree (AST)
! [  ] Verificação de tipo de função
! [  ] Verificação de função já declarada
! [  ] Verificação de função não declarada
! [  ] Verificação de parâmetros de função
! [  ] Verificação de variável não declarada
```
