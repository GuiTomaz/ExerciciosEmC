#include <stdio.h>
#include <stdlib.h>
int* coletaCoeficiente(int g);
void calculaIntegral(int g, int* coef);
void calculaDerivada(int g, int* coef);
void polinomioFornecido(int g, int* coef);
int main(void){
  //Recebe o polinomio
  int g; //maior valor do polibomio
  int* coeficientes;
  printf("Informe o valor do maior grau do polinomio que quer integrar/derivar: (maior expoente) ");
  scanf("%d",&g);
  while(g > 0){
    coeficientes = coletaCoeficiente(g);
    polinomioFornecido(g, coeficientes);
    calculaIntegral(g, coeficientes);
    calculaDerivada(g, coeficientes);
    printf("\n -----------------------------");
    printf("\n Informe o valor do maior grau do polinomio que quer integrar/derivar: (maior expoente) ");
    scanf("%d",&g);
  }

  free(coeficientes);
  return 0;
}
int* coletaCoeficiente(int g){
  int* coef = (int*) malloc(sizeof(int)*g+1);
  for(int c = 0;c<g+1;c++){
    printf("\nInforme o coeficiente que acompanha x^%d: ", c);
    scanf("%d",&coef[c]);
    printf("\n -------------");
  }
  return coef;

}
void calculaIntegral(int g, int* coef){
  //Algoritmo para calcular a integral do polinomio dado
  float integral[g+2];
  integral[0]=0;//representa a constante 'c';
  for(int i =0;i<g+1;i++){
    integral[i+1] =  coef[i] / (i+1)*1.0;
  }

  //Exibe a Integral
  printf("\n Integral: ");
  for(int k = g+1;k>0;k--){
    printf("(%.0fx^%d) + ",integral[k],k);
  }
  printf(" c ");
}

void calculaDerivada(int g, int* coef){
  //Algoritmo para calcular a derivada
  int derivada[g];
  for(int z = 1;z<g+1;z++){
    derivada[z-1] = coef[z]*z;

  }

  //Exibe a derivada
  printf("\n Derivada: ");
  for(int x = g-1;x>=0;x--){
    printf("(%dx^%d) + ", derivada[x],x);
  }
  printf(" 0 ");
}

void polinomioFornecido(int g, int* coef){
  printf("\nPolinomio fornecido: ");
  for(int i = g;i>=0;i--){
    printf("(%dx^%d) + ", coef[i],i);
  }
  printf(" 0 \n");
}