# 최소 스패닝 트리를 구하는데 사용되지 않은 간선의 길이를 모두 더해주면 
# 최소 스패닝 트리 조건을 만족하기 위해 줄일 수 있는 간선의 최대 길이를 구할 수 있다.

import sys
input = sys.stdin.readline


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    x = find_parent(parent, a)
    y = find_parent(parent, b)
    if x < y:
        parent[y] = x
    else:
        parent[x] = y


def kruskal():
    m, n = map(int, input().split())
    if m ==0 and n==0:
        sys.exit()
    parent = [0] * (n+1)
    edges = []
    total = 0
    used = 0
    for i in range(1, n+1):
        parent[i] = i

    for _ in range(n):
        a, b, cost = map(int, input().split())
        total += cost
        edges.append((cost, a, b))

    edges.sort()

    for edge in edges:
        cost, a, b = edge
        if find_parent(parent, a) != find_parent(parent, b):
            union_parent(parent, a, b)
            used += cost
            
    print(total-used)

while True:
    kruskal()
