
a = '1 2 3 4 5'
arr = list(map(int, a.strip().split(' ')))


sum = 0
for i in arr:
    sum += i
maxnum = sum - min(arr)
minnum = sum - max(arr)

print(maxnum, minnum)
