import sys

n = int(input())
d = [1] * (n)
height = list(map(int, input().split()))

for i in range(1, len(height)):
    temp = []
    for j in range(i-1, -1, -1):
        if height[i] > height[j]:
            temp.append(d[j])
    if len(temp) != 0:
        d[i] = max(temp) + 1

print(max(d))