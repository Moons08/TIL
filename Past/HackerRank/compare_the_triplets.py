
import sys

def solve(a0, a1, a2, b0, b1, b2):
    # Complete this function
    a = list(zip([a0, a1, a2], [b0, b1, b2]))
    ap, bp = 0, 0
    for i in a:
        if i[0]> i[1]:
            ap +=1
        elif i[0]<i[1]:
            bp +=1
    return (ap, bp)


a0, a1, a2 = input().strip().split(' ')
a0, a1, a2 = [int(a0), int(a1), int(a2)]
b0, b1, b2 = input().strip().split(' ')
b0, b1, b2 = [int(b0), int(b1), int(b2)]
result = solve(a0, a1, a2, b0, b1, b2)
print (" ".join(map(str, result)))
