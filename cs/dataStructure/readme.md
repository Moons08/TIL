# Data Structure

## Linked List

- 구조체 & 포인터
- 필요할때마다 메모리 공간 할당
- insert, delete가 배열보다 간단
- direct access 불가

### vs. Array

- 삽입 삭제가 많은 경우 이점
- 조회가 많은 경우에는 배열이 나음

### Doubly Linked List

- 양방향에서 접근할 수 있음
- 추가 메모리 공간 필요하지만 안정적

## Queue

- 선입선출

## Stack

- 후입선출

## Binary Tree

하나의 루트 노드로부터 각 노드가 최대 2개의 자식 노드를 가질 수 있는 트리 구조

- Full Binary Tree
  - 리프 노드 제외 모든 노드가 두 자식 가짐
- Complete Binary Tree
  - 왼쪽부터 하나씩 채워짐
- Heigth Balanced Tree
  - 좌우 자식 트리의 높이가 2 이상 차이나지 않음

### binarySearchTree

이진 탐색이 항상 동작하도록 구현한 자료구조
부모 노드가 왼쪽자식보다는 크고 오른쪽 자식보다는 작다

### AVL Tree

균형이 갖춰진 이진트리.  
양쪽 자식 간의 높이 차인 균형 인수(Balance Factor)를 이용하며, 모든 노드의 균형 인수가 1, 0, -1인 트리를 의미  
O(logN)의 시간복잡도로 검색 가능.  

## Priority Queue

우선 순위를 가진 데이터들을 저장하는 큐. 일반적으로 최대 힙(Max Heap)으로 구현한다.  
최대 힙이란 부모 노드가 자식 노드보다 값이 큰 완전 이진 트리를 의미한다.
삭제 시에는 항상 루트 노드를 삭제하고, 가장 마지막 원소를 루트 자리에 옮긴 뒤, 리프노드로 내려가며 최대 힙을 유지한다.  
삽입 시에는 루트 노드까지 거슬러 올라가며 최대 힙을 유지한다.  

## graph

정점(Vertex)와 간선(Edge)로 데이터를 표현하며, 인접 행렬과 인접 리스트로 구현할 수 있다.

### 인접 행렬

모든 정점 간의 연결 여부를 행렬로 저장하기 때문에 O(V^2)의 공간이 필요하지만, 정점 간 연결 확인에는 O(1) 시간 필요

### 인접 리스트

연결된 간선 정보만 저장하여 O(E)의 공간 요구하지만 정점 간 연결 확인에는 O(V)의 시간 필요

## Hash

최대한 빠른 속도로 데이터를 관리하기 위한 구조. 메모리 공간이 많이 소모되지만 속도가 빨라서 데이터베이스 등에서 활용된다.
