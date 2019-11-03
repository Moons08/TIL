'''계수정렬; O(n+k)의 복잡도, (k 는 정렬할 값 중 가장 큰 값)
누적합이 숫자들의 인덱스 역할
정렬 중 개인적으로 이해하기 제일 힘들었음...
'''

#정수만 가능, 최소, 최댓값 입력 필요
def countingSort(ls, smallest, largest):

    # 최솟값, 최댓값을 정확히 입력할 경우 불필요한 메모리 낭비 방지
    size = largest - smallest +1 #카운팅할 크기(범위) 설정
    count = [0]*size # 초깃값을 0으로 넣는다.

    # 각 원소를 카운팅
    for i in ls:
        count[i-smallest]+=1 # 작은 값부터 카운팅

    index = 0 # 현재위치

    # 범위만큼 반복
    for i in range(size):
        # 각 숫자 카운팅만큼 반복 입력(2가 2개면 2를 2번 입력)(2가 2개면 2를 2번 입력)
        # count = 0 인 경우 자동 스킵
        for j in range(count[i]): #0 0 01 0

            ls[index] = i + smallest # 현재위치에 입력 (아까 뺀 최솟값을 더함)
            index += 1 # 다음 자리로 이동

ls = [2, 1, 1, -1, 0]
countingSort(ls, -1, 2)
print(ls) # [-1, 0, 1, 1, 2]
