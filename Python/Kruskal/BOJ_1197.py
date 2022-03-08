# 신장 트리 : 하나의 그래프에서 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프
# 최소 비용 신장 트리 -> 크루스칼 알고리즘
# 크루스칼 알고리즘은 그리디 알고리즘으로, 먼저 모든 간선에 대해 정렬 수행 후 가장 거리가 짧은 간선부터 집합에 포함시킨다.


def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]


def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


v, e = map(int, input().split())
parent = [0] * (v+1)
edges = []
result = 0

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
        result += cost

print(result)
