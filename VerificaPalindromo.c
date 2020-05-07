#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int verificaPalindromo(char* s);

int main(void){
  char numero[50];
  int numInt;
  do{
    printf("Insira um numero: ");
    scanf("%s",numero);
    numInt = atoi(numero);
    if(verificaPalindromo(numero)){
      printf("\n VERDADEIRO (Palindromo) \n");
    }else{
      printf("\n FALSO \n ");
    }
  }while(numInt>=0);

  return 0;
}

int verificaPalindromo(char* s){
  char* s2 = (char*) malloc(sizeof(char)*50);
  //Primeiro copiamos s para s
  int i;
  for(i =0;i<strlen(s);i++){
    s2[i] = s[i];
  }
  s2[i]= '\0';
  //Vamos comparar s com s2, sendo que s2 sera lido de tras para frente e s lido na ordem normal
  for(int z = 0;z<strlen(s);z++){
    if(!(s[z] == s2[strlen(s2)-(z+1)])){
      return 0; //retorna falso, nao eh palindromo
    }
  }
  free(s2);
  return 1;
}