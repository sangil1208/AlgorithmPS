from collections import deque
case = int(input())
result = []

for i in range(case):
    n, m = map(int, input().split())
    temp = deque(map(int, input().split()))
    top = max(temp)
    if temp[0] != top:
        temp.append(temp.popleft())


print(result)
