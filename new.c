#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool six_exists(char *s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '6')
        {
            return true;
        }
    }
    return false;
}

bool total(char *s)
{
    int total = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        total += s[i] - '0';
    }
    if (total % 10 == 8)
        return true;
    else
        return false;
}

bool check(char *s)
{
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    for (long long i = a; i <= b; i++)
    {
        char num[10];
        sprintf(num, "%lld", i);
        if (six_exists(num) && check(num) && total(num)) printf("%s ", num);
    }
}
