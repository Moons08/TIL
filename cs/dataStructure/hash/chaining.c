#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

typedef struct {
    int id;
    char name[20];
} Student;

typedef struct {
    Student *data;
    struct Bucket *next;
} Bucket;

// 연결리스트를 이용하여 동일 키를 가지는 항목들을 연결해서 보관

void init(Bucket **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;}
}

void destructor(Bucket **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) free(hashTable[i]);
    }
}

int isExist(Bucket **hashTable, int id) {
    int i = id % TABLE_SIZE;
    if (hashTable[i] == NULL) return 0; // 키가 비어있는 경우
    else {
        // 키가 이미 할당된 경우, 연결리스트의 가장 마지막 노드를 찾음
        Bucket *cur = hashTable[i];
        while (cur != NULL) { // 비어있는 cur 만날때까지 반복
            if (cur->data->id == id) return 1; // 중복 id인 경우 리턴, 입력 X
            cur = cur->next;
        }
    }
    return 0;
}

void add(Bucket **hashTable, Student *input) {
    int i = input->id % TABLE_SIZE;
    if (hashTable[i] == NULL) { // 해당 키 값이 비었으면 메모리 할당 후 값 입력
        hashTable[i] = (Bucket*)malloc(sizeof(Bucket));
        hashTable[i]->data = input;
        hashTable[i]->next = NULL;
    } else {
        // 해당 키 값이 이미 할당된 경우, 맨 앞에 넣을 값을 연결
        Bucket *cur = (Bucket*)malloc(sizeof(Bucket));
        cur->data = input;
        cur->next = hashTable[i]; // 입력 전 가장 맨 앞 버켓을 연결
        hashTable[i] = cur;
    }
}

void show(Student **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != NULL) {
            Bucket *cur = hashTable[i];
            while (cur != NULL) {
                printf("키: [%d] 이름: [%s]\n", i, hashTable[i]->name);
                cur = cur->next;
            }
        }
    }
}

int main(void) {
    Bucket **hashTable;
    hashTable = (Bucket**)malloc(sizeof(Bucket) * TABLE_SIZE);
    init(hashTable);

    for (int i = 0; i < INPUT_SIZE; i++)
    {
        Student *student = (Student*)malloc(sizeof(Student));
        student->id = rand() % 1000000;
        sprintf(student->name, "사람%d", student->id);
        if (!isExist(hashTable, student->id)) {
            add(hashTable, student);
        }
    }
    
    show(hashTable);
    destructor(hashTable);
    return 0;
}