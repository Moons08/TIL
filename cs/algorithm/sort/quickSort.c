#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// #define SIZE 1000

// int a[SIZE];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void show(int *a, char *input) {
    /** 동적으로 할당한 배열의 사이즈를 보는 것은 생각보다 험난한 길이...
    * 정적일 때는 sizeof(a)/sizeof(int) 이런식으로 쓰지만
    * 동적일 떄는 sizeof(&a)는 포인터 크기(8byte)가 된다.
    * c++에는 컨테이너란 것이 있어서 size() 따위를 쓸 수 있다더라.
    */
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("%s \n", input);
}

void quickSort(int *a, int start, int end) {
    show(a, "start!");
    printf("pivot: %d\n", a[start]);

    if (start >= end) return;
    int pivot = start, i = start + 1, j = end, temp;
    while (i <= j) {
        
        while (i <= end && a[i] <= a[pivot]) i++; 
            // pivot보다 작고 end 까지 안왔으면 냅두고 다음
        while (j > start && a[j] >= a[pivot]) j--;
            // pivot보다 크고 start까지 안왔으면 냅두고 다음
        if (i > j) {
            // 엇갈린 경우 pivot랑 마지막 큰 놈 스왑 -> 키 왼쪽엔 작은 놈들, 오른쪽에는 큰 놈들
            swap(&a[pivot], &a[j]); 
            show(a, "pivot change!");
            printf("\t %d %d\n", a[pivot], a[j]);
        }    
        else {
            // 아닌경우 양쪽 놈들 스왑
            swap(&a[i], &a[j]); 
            show(a, "swap!");
            printf("\t %d %d\n", a[i], a[j]);
        }
    }
    quickSort(a, start, j-1);
    quickSort(a, j+1 , end);
}

int main(void) {
    int n;  
    scanf("%d", &n);
    int *a = (int*)calloc(n , sizeof(int)); // malloc과 다르게 0으로 초기화해서 메모리할당
    show(a, "check");

    for (int i = 0; i < n; i++) scanf("%d", &a[i]); // 입력 받고
    quickSort(a, 0, n-1);
    show(a, "done!");
 
    return 0;
}