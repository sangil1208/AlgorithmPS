# 10870문제와 같이 재귀적으로 메모이제이션을 구현하고, fibo(0) 이나 fibo(1)이 출력될 때
# 각각 전역변수 zero_cnt와 one_cnt의 값을 1씩 증가시킨다.
# 미해결

import sys
input = sys.stdin.readline
n = int(input())
fibo_list = []
for _ in range(n):
    fibo_list.append(int(input()))

zero = [0]*100
one = [0]*100

def fibo(x):
    if x==0:
        zero[x] = 1
        return 0
    if x==1:
        one[x] = 1
        return 1
    if zero[x]!=0:
        return zero[x]
    if one[x]!=0:
        return one[x]
    zero[x] = zero[x-1] + zero[x-2]
    one[x] = one[x-1] + one[x-2]
    d[x] = fibo(x-1) + fibo(x-2)
    return d[x]

for x in fibo_list:
    d = [0]*100
    zero_cnt = 0
    one_cnt = 0
    fibo(x)
    print(zero_cnt, end=' ')
    print(one_cnt)
    
   


