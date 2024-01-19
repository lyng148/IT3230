#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int thutuc(int a[], int left, int right){
    int i = left - 1;
    int pivot = a[right];
    for (int j = left; j < right; j++) {
        if (a[j] <= pivot){
            swap(&a[++i], &a[j]);
        }
    }
    swap(&a[++i], &a[right]);
    return i;
}

void quicksort(int a[], int left, int right){
    if (left < right){
        int pos = thutuc(a, left, right);
        quicksort(a,left,pos - 1);
        quicksort(a, pos + 1, right);
    }
}

int main(){
   
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < 4; i++){
        printf("%d ", a[i]);
    }
}