'''버블 정렬은 O(n^2)로 성능이 가장 좋지 않다.
하지만 코드가 단순하기 때문에 종종? 사용된다고 한다.
'''
def bubbleSort(array):
    length = len(array) - 1 # list index out of range 방지용 -1

    for i in range(length): # 0 1 2 3
            # 뒤로 가있는 수는 제자리를 찾았기 때문에 length - i 로 불필요한 반복 제거
        for j in range(length - i): # 0123 012 01 0

            if array[j]>array[j+1]: # 자기보다 큰수가 나올 때 까지 뒤로 이동
                array[j], array[j+1] = array[j+1], array[j]

    return array

print(bubbleSort([1, 5, -1, 4, 2])) #[-1, 1, 2, 4, 5]
