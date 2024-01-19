#include <stdio.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[r]);
    return i + 1;
}

void quickSort(int *arr, int l, int r) {
    if (l < r) {
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int minimumDifference(int *arr, int n, int m) {
    if (m == 1) {
        return 0;
    }

    quickSort(arr, 0, n - 1);

    int minDiff = arr[m - 1] - arr[0];
    for (int i = 1; i <= n - m; i++) {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}

int main() {
    int n, m;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &m);

    int result = minimumDifference(arr, n, m);

    printf("%d\n", result);

    return 0;
}
