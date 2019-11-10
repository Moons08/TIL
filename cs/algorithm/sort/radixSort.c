#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 1000


void radixSort(int *a, int n) {
    int res[MAX], maxValue = 0;
    int exp = 1; // 자릿값 
    for (int i = 0; i < n; i++)    {
        if (a[i] > maxValue) maxValue = a[i]; // 최댓값 찾기
    }

    while (maxValue / exp > 0)    {
        int bucket[10] = { 0 } ;
        for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++; // 자릿값으로 나눈 몫을 10으로 나눈 나머지 입력
        for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; // 누적값 계산
        for (int i = n-1; i >= 0; i--) { // 뒤에서부터 시작
            res[--bucket[a[i] / exp % 10]] = a[i]; // bucket 카운트 하나 줄이고 결과 값에 
        };
        for (int i = 0; i < n; i++) a[i] = res[i]; // 최초 배열에 입력
        exp *= 10; // 상위 자릿수 정렬 
    }
    
}

int main(void) {
    int i, n;
    int a[MAX];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    radixSort(a, n);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
 
    return 0;
}