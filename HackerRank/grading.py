import sys

def solve(grades):
    # Complete this function
    for idx, val in enumerate(grades):
        if val < 38:
            continue
        elif val%5 >= 3:
            grades[idx] += 5 - val%5
    return grades

n = int(input().strip())
grades = []
grades_i = 0
for grades_i in range(n):
   grades_t = int(input().strip())
   grades.append(grades_t)
result = solve(grades)
print ("\n".join(map(str, result)))
