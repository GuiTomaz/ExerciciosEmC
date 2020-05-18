#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int meuStrLen(char *s);
void exibeString(char* s);
void concat(char* s1, char s2);
char** criaLista(int maxSubConjuntos);
int totSubConjuntos(int tamConjunto);
void guardaStringNaLista(char** lista,char* aux,int qtdSubConj);
void configInicial(int* totElementosString, int* maxSubConj, int* qtdSubConj, char* s);
void picotaEGuardaString(char* s, char* aux, int* qtdSubConj, char** L2);
void ordena(char** L, int totConj);
void copy(char*orig, char*dest);
void trocaString(char* s1, char* s2);
int encontreMaiorSub(char** L1, char** L2, int tamMaiorSub, int tamMenorSub);
int main() {
  char s[30];
  int totElementosString;
  int maxSubConj;
  int qtdSubConj;
  int qtdSubConjL1;
  int qtdSubConjL2;
  char aux[30];
  //Dissecando a primeira string
  scanf("%[^\n]%*c", s);
  configInicial(&totElementosString, &maxSubConj,&qtdSubConj, s);
  char** L = criaLista(maxSubConj);
  picotaEGuardaString(s, aux, &qtdSubConj, L);
  qtdSubConjL1 = qtdSubConj;
  ordena(L, qtdSubConj);
  //Dissecando a segunda String
  scanf("%[^\n]%*c", s);
  configInicial(&totElementosString, &maxSubConj, &qtdSubConj, s);
  char** L2 = criaLista(maxSubConj);
  picotaEGuardaString(s, aux, &qtdSubConj, L2);
  qtdSubConjL2 = qtdSubConj;
  ordena(L2, qtdSubConj);
  if(qtdSubConjL1 >= qtdSubConjL2){
      if(encontreMaiorSub(L,L2,qtdSubConjL1, qtdSubConjL2)){

        printf("Substring nao encontrada");
      }else{
        printf("\n Programa finalizado com sucesso...\n");

      }
  }else{
    if(encontreMaiorSub(L2,L,qtdSubConjL2, qtdSubConjL1)){
      printf("Substring nao encontrada");
    }else{
      printf("\n Programa finalizado com sucesso...\n");
    }

  }
  return 0;
}
int encontreMaiorSub(char** L1, char** L2, int tamMaiorSub, int tamMenorSub){
  char sub[30];
  for(int i =tamMaiorSub-1;i>=0;i--){
    for(int k =tamMenorSub-1;k>=0;k--){
        if(meuStrLen(L1[i])>meuStrLen(L2[k])){
          break;
        }else{
          if(strcmp(L1[i], L2[k]) == 0){
            copy(L2[k], sub);
            printf("Resultado encontrado: %s ", sub);
            return 0;

          }
        }
    }
  }
  return 1;
}
void ordena(char** L, int totConj){
  for(int i=0;i<totConj;i++){
    for(int k = i+1;k<totConj;k++){
      if(meuStrLen(L[i])>meuStrLen(L[k])){
        trocaString(L[i],L[k]);
      }
    }
  }
}

void trocaString(char* s1, char* s2){
  char aux[30];
  copy(s1,aux);
  copy(s2,s1);
  copy(aux,s2);
}
void copy(char*orig, char*dest){
  int i;
  for( i =0;orig[i]!='\0';i++){
    dest[i] = orig[i];
  }
  dest[i] = '\0';
}

void picotaEGuardaString(char* s, char* aux, int* qtdSubConj, char** Lista){
  /*
    Esta funcao vai cortar
  */
  for(int i =0;i<meuStrLen(s)-1;i++){
    aux[0] = s[i];
    aux[1] = '\0';
    for(int k = i+1;k<meuStrLen(s);k++){
      concat(aux, s[k]);
      guardaStringNaLista(Lista, aux, *(qtdSubConj));
      *(qtdSubConj)= *(qtdSubConj) + 1;
    }
    aux[0] = '\0';
  }
}
void configInicial(int* totElementosString, int* maxSubConj, int* qtdSubConj, char* s){
  /*
    Verifica quantos elementos tem a string, o maximo de sub conjuntos que ela pode ter, inicializa a quantidade de sub conjuntos encontrados
    para 0.
  */
  *(totElementosString) = meuStrLen(s);
  *(maxSubConj) = totSubConjuntos(*(totElementosString));
  *(qtdSubConj)= 0;

}
void guardaStringNaLista(char** lista,char* aux,int qtdSubConj){
  int i;
  for( i =0;aux[i]!='\0';i++){
    lista[qtdSubConj][i] = aux[i];
  }
  lista[qtdSubConj][i] ='\0';
}
char** criaLista(int maxSubConjuntos){
  char** listaDeSubConj = (char**) malloc(sizeof(char*)*maxSubConjuntos);
  for(int i =0;i<maxSubConjuntos;i++){
    listaDeSubConj[i] = (char*) malloc(sizeof(char)*30);
  }
  return listaDeSubConj;
}

int totSubConjuntos(int tamConjunto){
  int param = tamConjunto -1;
  return (param+1)*param/2;

}

int meuStrLen(char* s){
  int tam = 0;
  for(int i =0;s[i]!='\0';i++){
    tam++;
  }
  return tam;
}
void concat(char* s1, char s2){
  int fimDest = meuStrLen(s1);
  s1[fimDest] = s2;
  fimDest++;
  s1[fimDest]='\0';

}
 void exibeString(char* s){
  for(int i =0;s[i]!='\0';i++){
    printf("%c",s[i]);
  }
  printf(" ");
 }