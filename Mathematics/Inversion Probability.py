# Problem Name: Inversion ProbabilityProblem Link: https://cses.fi/problemset/task/1728/
# Idea:
# Complexity:
# Resource:
# I just conveted my C++ code to python(using decimal library for better precision)
from decimal import Decimal, getcontext
getcontext().prec = 50

import sys
input = sys.stdin.read
data = input().split()

n = int(data[0])
a = [Decimal(x) for x in data[1:n+1]]

ans = Decimal(0)

for i in range(n):
    for j in range(i + 1, n):
        if a[i] >= a[j]:
            inv_cnt = a[j] * (a[j] - Decimal(1)) / Decimal(2) + a[j] * (a[i] - a[j])
        else:
            inv_cnt = a[i] * (a[i] - Decimal(1)) / Decimal(2)
        
        ans += inv_cnt / (a[i] * a[j])

print(f"{ans:.6f}")

