# 1. n보다 한 칸 비어있는 경우 채울 수 있는 경우의 수 1가지
# 2. n보다 두 칸 비어있는 경우 채울 수 있는 경우의 수 2가지
# 2에서 3가지라고 생각할 수 있지만, 세로로 2개 채우는 경우는 1에서 계산하므로 제외
# d[n] = d[n-1] + d[n-2]*2 라는 점화식 도출, DP로 해결

import sys
input = sys.stdin.readline
n = int(input())

d = [0]*1001
d[1] = 1
d[2] = 3

for i in range(3, n+1):
    d[i] = d[i-1] + d[i-2]*2
    
print(d[n]%10007)