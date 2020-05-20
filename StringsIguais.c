#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
  Aproveitando a funcao  compara criada no problema "String contida", podemos resolver este problema facilmente.
*/
int compara(char* str1, char* str2);
int main() {
  char str1[30];
  char str2[30];
  scanf("%[^\n]%*c", str1);
  scanf("%[^\n]%*c", str2);
  if(compara(str1, str2) == 1){
    printf("As strings sao iguais\n");
  }else{
    printf("As strings sao diferentes\n");
  }

  return 0;
}


int compara(char* str1, char* str2){
  int i =0;
  if(strlen(str1) != strlen(str2)){
    return 0; // se possuem tamanhos diferentes, certamente serao diferentes
  }

  while(str1[i]!='\0'){
    if(str1[i] != str2[i] && (str1[i] + 32 != str2[i] && str1[i]-32!=str2[i])){
      return 0;
    }
    i++;
  }
  return 1;
}