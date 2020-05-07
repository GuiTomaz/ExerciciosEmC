#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int numberConvert(char s);
int main(void){

  char A[20];
  char B[20];
  int analise[9] = {0,0,0,0,0,0,0,0,0};
  int digA,digB,c = 0;
  /*
    O vetor analise ira considerar a quantidade de elementos para cada digito do numero fornecido. Se dois numeros, tem a mesma quantidade
    de digitos e a mesma quantidade dos mesmos digitos repetidos(quando houve repetição), entao, eh uma permutacao. Afinal, uma permutacao
    A de B acontece se ambos tiverem os mesmos elementos mas ordenados de forma diferente
    indice // digito
       0         1
       1         2
       2         3
       3         4
       4         5
       5         6
       6         7
       7         8
       8         9

    Ou seja, a quantidade de vezes que o digito '1' apareceu será armazenada em analise[0], o mesmo acontece com os outros numeros.

    Após isso, capturaremos a quantidade de digitos e de elementos repetidos no numero B, e subtraíremos cada quantidade do vetor analise
    Se  A eh permutacao de B, entao, no fim, o vetor analise tem que restar 0 em todos os seus elemtnos.
    Exemplo: se temos o numero 123, teremos... analise = [1,1,1,0,0,0,0,0,0]
    Se B for 321, primeiro, ele analisa o primeiro digito de B, então programa ira soma -1 a analise[2](consultar tabela acima), apos isso
    ele repete o mesmo processo com outros numeros
  */
  printf("Informe o numero A: ");
  scanf("%s", A);
  printf("Informe o numero B: ");
  scanf("%s",B);
  if(strlen(A)>strlen(B) || strlen(B)>strlen(A)){
    printf("Ambos os numeros possuem quantidades distintas de numeros, logo, A nao eh permutacao de B e vice versa.");
    return 0;
  }else{
    for(int i =0;i<strlen(A);i++){
    //Calcula a quantidade de vezes que um digito apareceu em A, se sim, ele soma a analise[digito -1 ]
    digA = numberConvert(A[i]);
    analise[digA-1]++;
  //Calcula a quantidade de vezes que um digito aparceu B, porem, se sim, ele  subtrai em analise[digito-1], pois a ideia eh que analise so tenha elementos 0, caso A seja permutacao de B
    digB = numberConvert(B[i]);
    analise[digB-1] = analise[digB-1] -1;
    }

    while(c<strlen(A)){

      if(analise[c] != 0){
        printf("A nao eh permutacao de B");
        return 0;
      }
      c++;
    }

  }


  printf("A eh permutacao de B!");
  return 0;
}

int numberConvert(char s){
  // Converte um char para int, mas nao considera possiveis erros como a insercao de uma letra ao inves de numero
  int num = s - '0';
  return num;
}