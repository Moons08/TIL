#include <stdio.h>
#define INF 10000

int arr[INF];
int count = 0;

void addBack(int data) {
    // 가장 뒤에 입력 후 길이 추가
    arr[count] = data;
    count++;
};

void addFirst(int data) {
    // 모든 값 하나씩 밀어내고 가장 앞에 값 추가
    for (int i = count; i >=1 ; i--) {
        arr[i] = arr[i - 1]; // a[3] = a[2], a[2] = a[1], a[1] == a[0]
    }
    arr[0] = data; // 새 값으로 덮어쓰기
    count++;
};

void removeAt(int index) {
    for (int i = index; i < count - 1; i++) {
        // 지정한 인덱스부터 뒤에서 하나씩 밀어내기
        arr[i] = arr[i + 1];
    }
    // 리스트 길이 하나 줄임
    count--;
}

void insertAt(int index, int value) {
    for (int i = count; i >= index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = value;
    count++;
}

void show() {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    addFirst(4);
    addFirst(5);
    addBack(3);
    addBack(5);
    show();
    removeAt(2);
    show();
    insertAt(1, 2);
    show();
    return 0;
}

/*
 5 4 3 5
 5 4 5
 5 2 4 5
 */
