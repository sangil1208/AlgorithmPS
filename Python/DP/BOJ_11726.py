# 1. n보다 한 칸 비어있는 경우 채울 수 있는 경우의 수 1가지
# 2. n보다 두 칸 비어있는 경우 채울 수 있는 경우의 수 2가지
# 하지만 2*1 두개로 2*2빈칸 채우는 경우는 1에서도 확인하게 되므로 n보다 두칸 비어있는 경우 채우는 경우도 1가지이다
# d[n] = d[n-1] + d[n-2] 라는 점화식 도출, DP로 해결

import sys
input = sys.stdin.readline

n = int(input())
d = [0]*1001
d[1] = 1
d[2] = 2

for i in range(3,n+1):
    d[i] = d[i-1] + d[i-2]
    
print(d[n]%10007)