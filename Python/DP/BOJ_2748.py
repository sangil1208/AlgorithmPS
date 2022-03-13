'''
이전에 계산된 피보나치 수는 재귀 수행될때 다시 계산하지 않고, 이전에 계산된 값이 있다면 해당 값을 그대로 사용한다.
재귀,계산 횟수 줄임. DP 방식
'''


import sys
input = sys.stdin.readline

d = [0]*91


n = int(input())


# 입력이 90보다 작거나 같은 자연수이므로 0은 처리 안해줘도 됨
def fibo(x):
    if x==1 or x==2:
        return 1
    if d[x] == 0:
        d[x] = fibo(x-1) + fibo(x-2)
    else:
        return d[x]
    
    return d[x]
        

print(fibo(n))
    