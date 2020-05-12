#include <stdio.h>
void codifica (char *str);
int main() {
  char s[40];
  printf("Informe uma palavra: ");
  scanf("%s", s);
  codifica(s);
  for(int i = 0;s[i]!='\0';i++){
    printf("%c", s[i]);
  }
  return 0;
}

void codifica(char *str){
  char c;
  int codeA[5] = {97, 101,105,111,117}; //numeros ASCII das vogais
  int letterCode;
  for(int i = 0; str[i] != '\0';i++){
      c = str[i];
      letterCode = c;
      for(int k = 0;k<5;k++){
        if(letterCode == codeA[k]){
          str[i] = '?';
        }
      }
  }
}