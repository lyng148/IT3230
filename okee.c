#include <stdio.h>

int main(){
    int n[] = {7,57,13,31,17,65,32,3,97,22,7,20,69,35,69,75,13,33,50,80,64,71,15,28,2,27,39,48,13,22,84,5,51,46,26,78,56,63};
    for (int i = 0; i < sizeof(n)/sizeof(n[0]) / 2; i++){
        int k = 130 - n[i];
        for (int j = sizeof(n)/sizeof(n[0]); j >= sizeof(n)/sizeof(n[0]) / 2 ; j--){
            if (k == n[j]) printf("%d ", k);
        }
    }
}