# algorithms

## sort

### selectionSort

O(N^2)  
가장 작은 값을 찾는데 N, 찾은 값을 차례로 앞에 갖다 놓는데 N

### insertionSort

O(N^2)  
모든 값에대해 N 왼쪽에는 작은 값이, 오른쪽에는 큰 값이 오도록 위치를 선택하는데 N

### quickSort

평균 O(Nlog N), 최악 O(N^2)  
분할정복이 핵심.

1. 정렬 대상 중 하나의 값을 선택(=피벗 값)
2. 피벗 값을 중심으로 왼쪽에는 작은 값이, 오른쪽에는 큰 값이 오도록 정렬
3. 피벗 값을 제외하고 왼쪽, 오른쪽 그룹에서 재귀적으로 1-2번 반복

### radixSort

기수 정렬. 자릿수를 이용하여(일의 자리 정렬->십의 자리 정렬->...) 데이터를 정렬.  
가장 큰 자릿수가 D라고 할 때, O(DN)의 시간 복잡도로 동작

### countingSort

계수 정렬. 각 데이터의 값을 인덱스로 삼아 값의 개수를 배열의 값으로 넣어줌.  
많은 메모리를 요구하지만, 빠르게 동작 O(N)

## search

### sequentialSearch

순차적으로 하나씩 탐색 O(N)

### binarySearch

탐색 범위를 절반씩 좁혀가며 탐색, 정렬된 상태에서만 가능 O(logN)

### graph - depthFirstSearch

빠르게 모든 경우의 수를 탐색할 때 이용. 스택 개념에 기초

### graph breadFirstSearch

깊이우선과 비슷하지만 너비를 우선.. 큐 개념에 기초

