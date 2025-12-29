#include <stdio.h>
#include <stdlib.h>

int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    int a[n];
    int s[m]; 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &s[i]);
    }

    qsort(a, n, sizeof(int), compareIntegers);
    qsort(s, m, sizeof(int), compareIntegers);

    int arr1pointer = 0; 
    int arr2pointer = 0; 
    int count = 0;     
    while(arr1pointer<n && arr2pointer<m){
        if (a[arr1pointer] < s[arr2pointer] - k) {
            arr1pointer++;
        }
        else if (a[arr1pointer] > s[arr2pointer] + k) {
            arr2pointer++;
        }
        else {
            count++; 
            arr1pointer++;
            arr2pointer++; 
        }
    }

    printf("%d", count); 
    return 0;
}
