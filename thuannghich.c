#include <stdio.h>
#include <stdbool.h>

/* bool check_prime(long long a){
    if (a == 0 || a == 1) return false;
    if (a == 2 || a == 3) return true;
    for (long long i = 2; i * i <= a; i++){
        if (a % i == 0) return false;
    }
    return true;
} */

bool count(long long a){
    if (a == 0 || a == 1) return false;
    long long count = 0;
    for (long long i = 2; i * i <= a; i++){
        if (a % i == 0){
            count++;
            while (a % i == 0){
                a /= i;
            }
        }        
    }
    if (a > 1) count++;
    if (count >= 3) return true;
    else return false;
}

long long reverse(long long a){
    long long rev = 0;
    while(a){
        rev = rev * 10 + a % 10;
        a /= 10;
    }
    return rev;
}


int main(){
    long long a, b;
    long long count2 = 0;
    scanf("%lld %lld", &a, &b);
    for (long long i = a; i < b; i++){
        if ((reverse(i) - i) == 0 && count(i) == true){
            printf("%lld ", i);
            count2++;
        } 
    }
    if (count2 == 0) printf("-1");
}
