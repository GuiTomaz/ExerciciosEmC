# ExerciciosEmC
Alguns exercícios em C de listas da minha faculdade ou problemas interessantes encontrados na internet ou em livros

# Problemas: 

  ## 1 - Gerador de Primos
  Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
  n e retorne os n primeiros números primos existentes. Seu programa para quando n for menor ou
  igual a zero.
  
  ## 2 - Calculadora de Integrais e Derivadas
  Implemente um programa que integre e derive polinômios. Cada polinômio é definido por um
  vetor que contém seus coeficientes. Por exemplo, o polinômio de grau dois 3x^2 + 2x + 12 terá um
  vetor de coeficientes v = {12,2,3}. Sua integral será I = {0, 12, 1, 1}, equivalente ao polinômio x^3 +
  x^2 + 12x, e sua derivada será D = {2, 6}, equivalendo ao polinômio 6x + 2. O programa deve,
  infinitamente: (a) receber o valor do maior grau g do polinômio, seguido de (g + 1) coeficientes; (b)
  calcular qual é a integral e a derivada do polinômio informado; e (c) imprimir os novos polinômios
  na tela. Este programa para somente quando o grau g do polinômio for menor ou igual a zero.

## 3 - Verificador de Permutação de números
Um número a é dito permutação de um número b se os dígitos de a formam uma permutação
dos dígitos de b. Exemplo: 5412434 é uma permutação de 4321445, mas não é uma permutação
de 4312455. Faça um programa que receba a e b e responda se a é permutação de b. Obs.:
Considere que o dígito 0 (zero) não deve aparecer nos números.

## 4 - Verificador de Palindromos
Implemente um programa que, infinitamente, teste se um número é um palíndromo (Dica: se
uma palavra pode ser lida, indiferentemente, da esquerda para a direita e vice-versa, ela é
considerada um palíndromo). Você deve passar o número a ser testado. O seu programa deverá
imprimir as seguintes mensagens “VERDADEIRO” (caso o número seja um palíndromo) ou
“FALSO” (caso o número não seja um palíndromo) na console. Seu programa para quando o
número for negativo.

## 5 - Conversor Binario
Implemente um programa que, infinitamente, receba, como parâmetro de entrada, um número
n e retorne a representação binária de n. Por exemplo, se n é igual a 12, a resposta deste
programa deve ser “1100”. Seu programa para quando n for menor que zero.

## 6 - Codificando Palavras
Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
“Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo:
  ```
  void  shift_troca_string (char *str);
  ```
A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.

## 7 - Codifica Palavras II
Implemente uma função em C que receba uma string como parâmetro e retorne a string com
todos os caracteres(neste caso, apenas vogais) minúsculos substituídos pelo caracter ‘?’. Por exemplo, se for passada a string
“Palavra-Teste-123”, a função deve retornar a string “P?l?vr?-T?st?-123”. A assinatura desta função
deve ser:
``` 
  void codifica (char *str);
```

## 8 - Retira Prefixo
Escreva uma função que receba, como entrada, uma cadeia de caracteres s e um inteiro n, e,
em seguida, retire o "prefixo" da cadeia s de tamanho n (isto é, retire os n primeiros caracteres). Se a
cadeia não tiver pelo menos n caracteres, deve ser impressa a mensagem "erro". Por exemplo, se s =
"abcdefghi" e n = 3, então a cadeia "defghi" deve ser impressa; com a mesma cadeia s e n = 17,
deve ser impresso "erro". O protótipo desta função é o seguinte:
```
void retira_inicio_n (char *str, int n);
```
