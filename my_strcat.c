#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *a, char *b)
{
    int i = 0, j = 0;
    char *s = (char *)malloc((strlen(a) + strlen(b) + 1) * sizeof(char));
    for (i; i < strlen(a); i++)
    {
        s[i] = a[i];
    }
    for (i; i < strlen(b) + strlen(a); i++)
    {
        s[i] = b[j++];
    }
    
    return s;
}

int main()
{
    char a[] = "Hello_";
    char b[] = "Sechthu";
    printf("%s", my_strcat(a, b));
}