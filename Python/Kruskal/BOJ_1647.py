# 마을을 두 개로 나누고, 각 마을마다 경로 길이 합이 최소가 되게 하려면
# 최소 신장 스패닝 트리 구한 후 경로 길이의 최댓값을 빼 주면 된다.

import sys
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


v, e = map(int, input().split())

edges = []
parent = [0] * (v+1)
result = []

for i in range(1, v+1):
    parent[i] = i

for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

edges.sort()

for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result.append(cost)

print(sum(result)-max(result))
