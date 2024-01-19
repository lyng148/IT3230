#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool check_snt(long long a)
{
    if (a == 1 || a == 0)
        return false;
    if (a == 2 || a == 3)
        return true;
    for (long long i = 2; i * i <= a; i++)
    {
        if (a % i == 0) return false;
    }
    return true;
}

bool check_num(long long a)
{
    if (check_snt(a) == false) return false;
    long long total = 0;
    while (a)
    {
        long long n = a % 10;
        total += n;
        if (check_snt(n) == false) return false;
        a /= 10;
    }
    if (check_snt(total) == false) return false;
    return true;
}

int main()
{
    long long a, b;
    scanf("%lld %lld", &a, &b);
    int count = 0;
    for (long long i = a; i < b; i++){
        if (check_num(i) == true) count++;
    }
    printf("%d\n", count);
}