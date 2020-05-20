#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cic(char* str1, char* str2);
char** alocarMemoria(int tamNecessario);
void concatenar(char* s1, char s2);
void exibe(char** lista, int qtdFatias);
void fatiarString(char* str1, char** lista, int qtdFatias, int tamStr2);
void armazenar(char* aux, char** lista, int indiceAtual);
void desalocarMemoria(char** memory, int qtdEnd);
int compara(char* str1, char* str2);
int main() {
  char str1[30];
  char str2[30];
  scanf("%[^\n]%*c", str1);
  scanf("%[^\n]%*c", str2);
  if(cic(str1,str2)){
    printf("%s esta contida em %s\n", str2, str1);
  }else{
    printf("As strings sao diferentes, a segunda nao esta contida na primeira\n");
  }

  return 0;
}
void desalocarMemoria(char** memory, int qtdEnd){
  for(int i =0;i<qtdEnd;i++){
    free(memory[i]);
  }
  free(memory);

}
int cic(char* str1, char* str2){
  int tamStr1 = strlen(str1);
  int tamStr2 = strlen(str2);
  int qtdFatias = tamStr1-(tamStr2-1);
  char** stringFatiada = alocarMemoria(qtdFatias);
  fatiarString(str1, stringFatiada, qtdFatias, tamStr2);
  //Finalmente tenta descobrir se a string2 esta em string1
  for(int i =0;i<qtdFatias;i++){
    if(compara(stringFatiada[i], str2) == 1){
      desalocarMemoria(stringFatiada, qtdFatias);
      return 1;
    }
  }
  desalocarMemoria(stringFatiada, qtdFatias);
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
void exibe(char** lista, int qtdFatias){
  for(int i =0;i<qtdFatias;i++){
    printf("%s ", lista[i]);
  }
}
void fatiarString(char* str1, char** lista, int qtdFatias, int tamStr2){
  char aux[30];
  int qtdArmazenada = 0;
  for(int i =0;i<qtdFatias;i++){
    aux[0] = str1[i];
    aux[1] ='\0';
    for(int k =i+1;k<i+tamStr2;k++){
      concatenar(aux, str1[k]);

    }
    armazenar(aux, lista, qtdArmazenada);
    qtdArmazenada++;
    aux[0]='\0';
  }
}

void armazenar(char* aux, char** lista, int indiceAtual){
  int i;
  for(i = 0;aux[i]!='\0';i++){
    lista[indiceAtual][i] = aux[i];
  }
  lista[indiceAtual][i] = '\0';
}
void concatenar(char* s1, char s2){
  int fimDest = strlen(s1);
  s1[fimDest]=s2;
  fimDest++;
  s1[fimDest]='\0';
}
char** alocarMemoria(int tamNecessario){
  char** memoria   = (char**) malloc(sizeof(char*)*tamNecessario);
  for(int i = 0;i<tamNecessario;i++){
    memoria[i] = (char*) malloc(sizeof(char)*30);
  }
  return memoria;
}