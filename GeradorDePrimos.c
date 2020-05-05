#include <stdio.h>
#include <stdlib.h>
int main(void){
  int num, n = 0, totDivisores = 0, qtdNumeros = 0;
  while(1){
    printf("\n Informe um numero: ");
    scanf("%d",&num);
    printf("Primos: ");
    while(qtdNumeros < num){
      for(int k = 1;k<=n;k++){
        if(n % k == 0){
          totDivisores++;
        }
      }
      if(totDivisores == 2){
        printf("%d ", n);
        qtdNumeros++;
      }
      totDivisores = 0;
      n++;
    }
    qtdNumeros = 0;
    n= 0;
    totDivisores = 0;
  }
  return 0;
}


