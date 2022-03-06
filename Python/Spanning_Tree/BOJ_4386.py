# 크루스칼 알고리즘 기본 코드를 이용하지만, 좌표 입력을 실수로 받고
# 좌표간 거리를 math라이브러리 함수를 사용해 따로 계산해서 cost로 사용한다.
# 또한 오차를 10^-2 까지 허용하므로 소수점 셋째자리에서 반올림하여 출력

import sys
import math
input = sys.stdin.readline


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent,  parent[x])
    return parent[x]


def union_parent(parent, a, b):
    x = find_parent(parent, a)
    y = find_parent(parent, b)
    if x < y:
        parent[y] = x
    else:
        parent[x] = y


v = int(input())

edges = []
temp = []
parent = [0] * (v+1)
result = 0

for i in range(1, v+1):
    parent[i] = i

for _ in range(v):
    a, b = map(float, input().split())
    temp.append((a, b))

for i in range(v):
    for j in range(i+1, v):
        cost = math.sqrt(pow((temp[i][0]-temp[j][0]), 2)+pow((temp[i][1]-temp[j][1]), 2))
        edges.append((cost, i+1, j+1))

edges.sort()

for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

print(round(result, 2))
