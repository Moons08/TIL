import sys

def diagonalDifference(a):
    # Complete this function
    primary, second = 0, 0
    for j in range(0, n):
        for i in range(0,n):
            if i == j:
                primary += a[j][i]
            if i + j == n-1:
                second += a[j][i]
    return abs(primary-second)

if __name__ == "__main__":
    n = int(input().strip())
    a = []
    for a_i in range(n):
       a_t = [int(a_temp) for a_temp in input().strip().split(' ')]
       a.append(a_t)
    result = diagonalDifference(a)
    print(result)
