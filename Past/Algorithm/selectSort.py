'''
버블 정렬만큼 간단하고 성능도 안좋음 O(n^2)
하지만 30 이하의 작은 수에서는 효과적인 정렬
또한 리턴값이 array라서 메모리 부담이 덜하다
'''

def selectionSort(array):
    length = len(array)
    for i in range(length-1): #0123
        minindex = i

        for j in range(1+i, length): #1234 234 34 4
            if array[j]<array[minindex]:
                minindex = j

        temp = array[minindex]
        array[minindex] = array[i]
        array[i] = temp

    return array


a = selectionSort([1, 4, 5, 3, 0, -2])
print(a) #[-2, 0, 1, 3, 4, 5]
