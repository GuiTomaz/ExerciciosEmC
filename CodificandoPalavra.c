#include <stdio.h>
void shift_troca_string (char *str);
int main() {
  char s[40];
  printf("Informe uma palavra: ");
  scanf("%s", s);
  shift_troca_string(s);
  for(int i = 0;s[i]!='\0';i++){
    printf("%c", s[i]);
  }
  return 0;
}

void shift_troca_string (char *str){
  char c;
  for(int i = 0; str[i] != '\0';i++){
      c = str[i];
      if(c>='A' && c<='Z'){
        if(c == 'A'){
          str[i] = 122;
        }else{
          str[i] = c + 32 - 1;
        }
      }else if(c>='a' && c<='z'){
        if(c == 'a'){
          str[i] = 90;
        }else{
          str[i] = c - 1 - 32;

        }
      }else{
        str[i] = '!';
      }
  }
}