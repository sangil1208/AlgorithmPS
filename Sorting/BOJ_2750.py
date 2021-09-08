# 파이썬에 내장된 sort함수 이용하면 Nlog(N) 시간복잡도를 보장하므로 이를

n = int(input())
a = []

for _ in range(n):
    a.append(int(input()))

a.sort()

for i in range(n):
    print(a[i])
