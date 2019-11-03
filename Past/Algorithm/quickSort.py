'''빠르다 (mergeSort의 두배) O(NlogN)
단, 운이 나쁘면 느리고 O(N^2), 같은 숫자들을 정렬할 경우 숫자가 섞일 수 있다.

임의의 pivot 값을 기준으로 좌측에는 작은 값, 우측에는 큰 값으로 정렬한다.
좌 우로 이분화된 리스트를 재귀적으로 반복.
'''
def quickSort(array):
    quickSortHelper(array,0,len(array)-1) #first, last값 설정

def quickSortHelper(array,first,last):
    if first<last: #길이가 2 이상일때

        splitpoint = partition(array,first,last) #rightmark에 위치한 기준값

        #재귀, last = 기준점 -1 => 반 나눈 왼쪽에 대해 정렬
        quickSortHelper(array,first,splitpoint-1)
        #재귀, first = 기준점 +1 => 반 나눈 오른쪽에 대해 정렬
        quickSortHelper(array,splitpoint+1,last)

def partition(array,first,last):
    pivotvalue = array[first] #가장 앞자리 수를 기준값으로 설정

    leftmark = first+1 # 2번째 숫자부터 비교 시작
    rightmark = last # 얘는 끝에서부터

    done = False
    while not done:
            #왼쪽순번이 오른쪽 순번보다 작고(앞순서), 기준 숫자보다 작을 때, 내버려 둠
        while leftmark <= rightmark and array[leftmark] <= pivotvalue:
            leftmark += 1 # 왼쪽 다음 순번으로
            #오른쪽 수가 기준보다 크고, 왼쪽 순번보다 클 때, 내버려 둠
        while array[rightmark] >= pivotvalue and rightmark >= leftmark:
            rightmark -= 1 # 오른쪽 다음 순번으로

        if rightmark < leftmark: #mark가 겹칠 경우,
            done = True # 끝
        else: # 겹치지 않으면, 서로 자리 교환
            temp = array[leftmark]
            array[leftmark] = array[rightmark]
            array[rightmark] = temp

    # 탐색 끝난경우, 기준점과 겹친자리 숫자 교환(기준점 오른쪽은 큰값,왼쪽은 작은값)
    temp = array[first]
    array[first] = array[rightmark]
    array[rightmark] = temp

    return rightmark #오른쪽 순번에 위치한 기준값을 리턴

ls = [1, 5, 2, -1, 3, 7]
quickSort(ls)
print(ls) #[-1, 1, 2, 3, 5, 7]


# 2. 조금더 간단하게, 그러나 보기만해도 느릴 것 같음 (from wikipedia)

def quicksort(ls):
    if len(ls) <= 1:
        return ls
    pivot = ls[len(ls)//2] # 중간에 위치한 값을 기준값으로
    left = []
    right = []
    equal = []
    for i in ls:
        if i < pivot:
            left.append(i)
        elif i > pivot:
            right.append(i)
        else:
            equal.append(i)

    # 리턴값을 재귀적으로
    return quicksort(left)+equal + quicksort(right)

print(quicksort([1, 5, -1, 2])) #[-1, 1, 2, 5]
