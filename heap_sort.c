#include <stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm vun đống
void heapify(int A[], int i, int N) {
    int L = 2*i; // Con trái của phần tử thứ i
    int R = 2*i+1; // Con phải của phần tử thứ i
    int max = i; // max lưu vị trí phần tử thứ i
    if(L <= N && A[L] > A[i]) // Nếu con trái của phần tử thứ i lớn hơn nó
        max = L; // Gán max lưu vị trí con trái
    if(R <= N && A[R] > A[max]) // Nếu con phải của phần tử thứ i lớn hơn nó hoặc lớn hơn con trái (lớn hơn cha)
        max = R; // Gán max lưu vị trí con phải
    if(max != i){ 
        swap(&A[i], &A[max]); // Đổi chỗ phần tử thứ i cho con lớn nhất của nó
        heapify(A,max,N); // Vun đống lại từ nút con này (lúc này đã chứa giá trị phần tử thứ i)
    }
}

// Hàm xây đống
void buildHeap(int A[], int N) {
    for(int i = N/2; i >= 1; i--) // Duyệt qua các nút trong
        heapify(A,i,N); // Vun đống cho các nút trong, tính từ các nút trong gần các nút lá nhất
}

// Hàm sắp xếp vun đống
void heapSort(int A[], int N) {
    // index tu 1 -> N
    buildHeap(A,N); // Xây đống
    for(int i = N; i > 1; i--) {
        swap(&A[1], &A[i]); // phần tử thứ nhất lúc này là lớn nhất nên chuyển xuống cuối, tạo thành dãy có thứ tự
        heapify(A, 1, i-1); // vun lại đống cho cây bắt đầu từ phần tử thứ 1 cho đến phần tử thứ i-1
    } 
}


