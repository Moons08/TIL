s, t = 7, 11
a, b = 5, 15
m, n = 3, 2
apple = [-2, 2, 1]
orange = [5, -6]

a_score, b_score = 0, 0
''' too slow
for i in apple:
    if (a + i) in list(range(s, t+1)):
        a_score +=1

for i in orange:
    if (b + i) in list(range(s, t+1)):
        b_score +=1

'''
for i in apple:
    if (a+i >= s) and (a+i <= t):
        a_score += 1

for i in orange:
    if (b+i >= s) and (b+i <= t):
        b_score +=1
