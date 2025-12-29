#include <stdio.h>
#include <stdlib.h>
 
int compareIntegers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
 
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
 
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
 
    qsort(arr, n, sizeof(int), compareIntegers);
    int count=1;
 
   for(int i=1; i<n; i++){
        if(arr[i]!=arr[i-1]){
            count+=1;
        }
   }
   printf("%d", count);
    return 0;
}