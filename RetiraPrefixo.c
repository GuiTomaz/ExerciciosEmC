#include <stdio.h>
#include <stdlib.h>
int meuStrLen(char *s);
void retira_inicio_n(char *str, int n);
void copyString(char* dest, char* orig);
void exibeString(char* s);
int main() {
  char word[50];
  int n;
  printf("Forneca uma cadeia de caracateres: ");
  scanf("%[^\n]%*c", word);
  printf("Agora forneca um numero n para determinar o quanto sera retirado do prefixo: ");
  scanf("%d",&n);
  if(n>meuStrLen(word)){
    printf("\nERRO!\n");
  }else{
    retira_inicio_n(word, n);
    exibeString(word);
  }
  return 0;
}

void retira_inicio_n(char* str, int n){
  char stringAux[meuStrLen(str)-n];
  int sAuxIndex = 0;
  for(int i = n;i<meuStrLen(str);i++){
    stringAux[sAuxIndex] = str[i];
    sAuxIndex++;
  }
  stringAux[sAuxIndex] = '\0';
  copyString(str, stringAux);
}

void copyString(char* dest, char* orig){
    int ind = 0;
    while(orig[ind] != '\0'){
      dest[ind] = orig[ind];
      ind++;
    }
    dest[ind] = '\0';
}

int meuStrLen(char* s){
  int tam = 0;
  for(int i =0;s[i]!='\0';i++){
    tam++;
  }
  return tam;
}

 void exibeString(char* s){
  for(int i =0;s[i]!='\0';i++){
    printf("%c",s[i]);
  }
 }