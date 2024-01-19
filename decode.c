#include <string.h>
#include <stdio.h>

int main(){
    char s[1000];
    fgets(s, 1000, stdin);
    int count = 0;
    for (int i = 0; i < strlen(s); i++){
        if (s[i] == s[i+1]) count++;
        else if (s[i] != s[i+1]){
            printf("%c", s[i]);
            printf("%d",++count);
            count = 0;
        }
        else if (i == strlen(s) - 1){
            printf("%c", s[i]);
            printf("%d",++count);
        }
    }
}