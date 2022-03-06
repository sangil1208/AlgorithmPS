# 앞 수들을 1,2,3 의 합으로 나타내는 경우의 수를 이용해 뒤 수의 경우의 수를 구한다.(dp)
import sys
input = sys.stdin.readline

N= int(input())
num = []
for _ in range(N):
    num.append(int(input()))
    
M = max(num)

d = [0]*12

d[1] = 1
d[2] = 2
d[3] = 4

for i in range(4,M+1):
    d[i] = d[i-1]+d[i-2]+d[i-3]
    
for i in num:
    print(d[i])