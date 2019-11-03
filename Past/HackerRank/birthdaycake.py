n = 4
ls = [3, 2, 1, 3]
#!/bin/python3

import sys

def birthdayCakeCandles(n, ar):
    # Complete this function
    lm = max(ar)

    a = [i for i in ar if i == lm]
    return len(a)
    # slow
    # count = 0
    # for i in ls:
    #     if max(ls) == i:
    #         count += 1
    # return count

n = int(input().strip())
ar = list(map(int, input().strip().split(' ')))
result = birthdayCakeCandles(n, ar)
print(result)
