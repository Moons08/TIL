#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a[SIZE];
int n, m;

int main(void) {
    scanf("%d", &n);

    for (int i = 0; i < n; i++) { 
        scanf("%d", &m); 
        a[m]++; 
        } // m 을 입력받고 m 위치 count +1

    for (int i = 0; i < SIZE; i++) {
        while (a[i] > 0) {
            printf("%d ", i); // 자릿값 출력
            a[i]--; // 자릿값에 저장한 카운트 -1
        }
    }
 
    return 0;
}