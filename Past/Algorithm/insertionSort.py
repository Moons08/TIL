def insertionSort(array):
    for i in range(1, len(array)):

        temp = array[i] # 숫자 선택 후, 임시 저장
        position = i # 현재 위치

        while position > 0 and array[position-1]>temp:
            # 첫번째 숫자는 건너뜀
            # 임시 저장한 숫자보다 앞자리 숫자가 클 경우 실행 & 작은 숫자가 나올때까지 반복
            # 앞자리 숫자가 작으면? 이미 sorting 되어있음. continue
            array[position] = array[position-1] # 앞자리 숫자를 뒷자리에 복사
            position = position -1 # 앞자리로 현재 위치 변경

        array[position]=temp # 임시 저장한 숫자를 위치 변경한 앞자리에 삽입
    return array

array = [5, 6, 1, 2, 4, 3]
insertionSort(array)
print(array) #[1, 2, 3, 4, 5, 6]


def inverseSort(array):
    for i in range(0, len(array)):
            temp = array[i]
            position = i

            while position > 0 and temp > array[position-1]:
                array[position] = array[position-1]
                position = position -1

            array[position]=temp
    return array

inverseSort(array)
print(array)
print(inverseSort([3, 6, 2, 1, 6])) # [6, 6, 3, 2, 1]
