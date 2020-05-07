#include <stdio.h>
#include <stdlib.h>
int* conversorBinario(int num);
void exibeBinario(int* bin);
int main(void){
  int num;
  int *binario;
  do{
    printf("Insira um numero: ");
    scanf("%d",&num);
    binario = conversorBinario(num);
    exibeBinario(binario);

  }while(num>=0);
  free(binario);
  return 0;
}
int* conversorBinario(int num){
  int res;
  int* bin = (int*) malloc(sizeof(int)*50);
  int tam = 0;
  while(num >0){
    res = num % 2;
    num = num / 2;
    bin[tam] = res;
    tam++;
  }
  bin[tam] = -1;
  return bin;
}

void exibeBinario(int* bin){
  //Detectta o "tamanho" do numero binario
  int tam = 0;
  while(bin[tam] != -1){
    tam++;
  }
  printf("Binario: ");
  for(int i = tam-1;i>=0;i--){
    printf("%d ", bin[i]);
  }
  printf("\n");
}