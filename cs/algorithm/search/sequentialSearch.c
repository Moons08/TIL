#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 1000

char **array;
int founded;

int main(void) {
    int n;
    char *word;
    word = malloc(sizeof(char) * LENGTH);
    scanf("%d %s", &n, word); // 찾을 문자열 입력

    array = (char**) malloc(sizeof(char*) * n);
    for (int i = 0; i < n; i++)
    {
        array[i] = malloc(sizeof(char) * LENGTH);
        scanf("%s", array[i]); // 찾을 대상 문자열 입력
    }
    for (int i = 0; i < n; i++)
    {
        //문자열 비교 함수 (같으면 0 반환)
        if (!strcmp(array[i], word)) 
        {
            printf("%d번째 원소입니다.\n", i + 1);
            founded = 1;
        }
    }
    if (!founded) printf("원소를 찾을 수 없습니다.\n");
    
    return 0;
}