#include <stdio.h>
#define MAX_SIZE 100000

int a[MAX_SIZE];

int search(int start, int end, int target) {
    if (start > end) return -9999;
    int mid = (start + end) / 2;
    if (a[mid] == target) return mid;
    else if (a[mid] > target) return search(start, mid-1, target);
    else return search(mid+1, end, target);
}

int main(void) {
    int n, target;
    scanf("%d %d", &n, &target);

    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    
    int result = search(0, n-1, target);

    if (result != -9999) printf("%d번째 원소입니다.\n", result+1);
    else printf("원소를 찾을 수 없습니다.\n");
    // 정렬되지 않은 배열에 대해서는 정상적인 탐색이 불가능하다.

    return 0;
}