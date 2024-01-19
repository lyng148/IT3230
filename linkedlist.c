#include <stdio.h>

void quicksort(double a, double b, double n){
    if(a < b){
        double c = a;
        a = b;
        b = c;
    }   
}

int main(){
    int a[10000];
    for (int i = 0; i < 100; i++){
        a[i] = 1;
    }
    a[0] = 0; 
    a[1] = 0;  
    for(int i = 2; i < 100; i++){
        if (a[i] == 1){
            for (int j = 2; j * i <= 100; j++){
                a[i * j] = 0;
            }
        }
    }
    for (int i = 0; i < 100; i++){
        if (a[i] == 1){
            printf("%d\n", i);
        }
    }
    return 0; 
}
