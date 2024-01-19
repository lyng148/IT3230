#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int thutuc(int a[], int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; j++){
        if (a[j] <= pivot){
            swap(&a[++i], &a[j]);
        }
    }
    swap(&a[++i], &a[r]);
    return i;
}

void quicksort(int a[], int l, int r){
    if (l < r){
        int pos = thutuc(a, l, r);
        quicksort(a, l, pos - 1);
        quicksort(a, pos + 1, r);
    }
}

int binarysearch(int a[], int n, int x){
    int l = 0; int r = n - 1; int res = -1;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (a[mid] <= x){
            res = mid;
            l = mid + 1;
        }
        else if (a[mid] > x){
            r = mid - 1;
        } 
       
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n); 
    /* for (int i = 0; i < n; i++){
        printf("%d ", a[i]);
    } */
    printf("\n%d", binarysearch(a, n, 2));
}