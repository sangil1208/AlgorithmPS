'''
이미 연결된 간선에 대해서 union_parent를 수행해주고,
나머지 모든 가능한 간선과 cost를 계산해서 edges 리스트에 넣어준다.
이후 크루스칼 알고리즘 수행
'''

import sys
input = sys.stdin.readline

def find_parent(parent, x):
    # 루트 노드가 아니라면, 루트 노드를 찾을 때가지 재귀적으로 호출
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

# 두 원소가 속한 집합을 합치기
def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


# 노드의 개수와 간선의 개수 입력받기
v, e = map(int, input().split())
parent = [0] * (v+1)

# 모든 간선을 담을 리스트와 최종 비용을 담을 변수
edges = []
result = 0

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

loc = []
for i in range(1, v+1):
    a, b = map(int, input().split())
    loc.append((i, a, b))
    
for _ in range(e):
    x, y = map(int, input().split())
    union_parent(parent, x, y)
    cost = ((loc[x-1][1] -  loc[y-1][1])**2 + (loc[x-1][2] - loc[y-1][2])**2)**(1/2)

# edges 전부 따로 추가해주기
for x in range(1, v+1):
    for y in range(1, v+1):
        if x!=y and y>x:
            cost = ((loc[x-1][1] -  loc[y-1][1])**2 + (loc[x-1][2] - loc[y-1][2])**2)**(1/2)
            edges.append((cost, x, y))

# 간선을 비용순으로 정렬
edges.sort()

# 간선을 하나씩 확인하며
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost

result = float(result)

print("%.2f" %result)