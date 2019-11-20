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

### countingSort

## search

### sequentialSearch

순차적으로 하나씩 탐색 O(N)

### binarySearch

탐색 범위를 절반씩 좁혀가며 탐색, 정렬된 상태에서만 가능 O(logN)

### graph - depthFirstSearch

빠르게 모든 경우의 수를 탐색할 때 이용. 스택 개념에 기초

### graph breadFirstSearch

깊이우선과 비슷하지만 너비를 우선.. 큐 개념에 기초

