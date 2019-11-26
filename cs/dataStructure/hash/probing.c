#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

// 중복키 발생시 키에 +1 하며 다음 키에 할당
// 충돌 발생시, 유사 데이터들이 밀집되는 집중 결합 문제 발생하기 쉬움

typedef struct {
    int id;
    char name[20];
} Student;

void init(Student **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

void destructor(Student **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != NULL) {
            free(hashTable[i]);
        }
    }
}

int findEmpty(Student **hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
        if (hashTable[i % TABLE_SIZE] == NULL) {
            return i % TABLE_SIZE;
        }
        i++;
    }
    /*  quatratic : +1 -> +완전제곱수
    for (int j = 1; j < TABLE_SIZE; j++) {
        if (hashTable[i % TABLE_SIZE] == NULL) {
            return i % TABLE_SIZE;
        }
        i = i + j*j
    }
*/
}

int search(Student **hashTable, int id) {
    int i = id % TABLE_SIZE;
    while (1) {
        if (hashTable[i % TABLE_SIZE] == NULL) return -1;
        else if (hashTable[i % TABLE_SIZE]->id == id) return i;
        i++;
    }
}

void add(Student **hashTable, Student *input, int key) {
    hashTable[key] = input;
}

Student *getValue(Student **hashTable, int key) {
    return hashTable[key];
}

void show(Student **hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (hashTable[i] != NULL) {
            printf("키: [%d] 이름: [%s]\n", i, hashTable[i]->name);
        }
    }
}

int main(void) {
    Student **hashTable;
    hashTable = (Student**)malloc(sizeof(Student) * TABLE_SIZE);
    init(hashTable);

    for (int i = 0; i < INPUT_SIZE; i++)
    {
        Student *student = (Student*)malloc(sizeof(Student));
        student->id = rand() % 1000000;
        sprintf(student->name, "사람%d", student->id);

        if (search(hashTable, student->id) == -1) { // 중복인 경우 입력 X
            int index = findEmpty(hashTable, student->id);
            add(hashTable, student, index);
        } 
        /* 중복입력 허용시 ?
        int index = search(hashTable, student->id)
        if (index == -1) {
            index = findEmpty(hashTable, student->id);
        } else {
            index = findEmpty(hashTable, index);
        }
        add(hashTable, student, index);
        */
    }
    
    show(hashTable);
    destructor(hashTable);
    return 0;
}