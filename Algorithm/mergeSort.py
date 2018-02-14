'''
O(NlogN) 성능, 복잡하지만 insertionSort(O(N^2))보다 좋음

그러나 새로운 배열을 리턴하기 때문에 추가적 메모리가 필요
또한, 30개 미만 길이인 경우 insertionSort와 차이 미미
'''

def mergeSort(array):
    if len(array) < 2:
        return array
    left = array[:len(array)//2]
    right = array[(len(array)//2):]
    return merge(mergeSort(left), mergeSort(right))
    # 반으로 쪼개고 쪼개고.. 분할 + 재귀


def merge(left, right):  # 최소 단위(1)까지 쪼개서 비교
    result = left + right # list 길이 설정
    k = 0
    while len(left) and len(right): # 둘 중 하나가 없어질 때까지

        if left[0] <= right[0]: # 둘 중 작은 값을 result에 넣는다
            result[k] = left.pop(0) # indexing + pop/ append 느림
        else:
            result[k] = right.pop(0)

        k +=1   # 하나 넣었으면 다음 자리로 이동

    while len(left): # 비교 후 남아있는 리스트를 몽땅 result에 넣는다.
        result[k] = left.pop(0)
        k += 1

    while len(right): # 남아있지 않다면 자동 스킵
        result[k] = right.pop(0)
        k += 1

    return result

print(mergeSort([1, 6, 5, 3, 7, 0, -1, -9])) #[-9, -1, 0, 1, 3, 5, 6, 7]
