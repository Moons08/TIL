#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n, index;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]); // 입력 받고

    for (int i = 0; i < n-1 ; i++) {
        int j = i;
        printf("%d\n", a[i]);
        while (j >=0 && a[j] > a[j+1]) { // 
            swap(&a[j], &a[j+1]); 
            j--;
            for (int i = 0; i < n; i++) printf("%d ", a[i]);
            printf("\n"); 
        }
    };

    for (int i = 0; i < n; i++) printf("%d ", a[i]); 
 
    return 0;
}