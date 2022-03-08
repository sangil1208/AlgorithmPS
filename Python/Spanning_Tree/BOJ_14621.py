'''
남-남 혹은 여-여 학교끼리는 연결 불가하므로, 해당 edge는 입력 받은 후 edges리스트에 추가시키지 않음.
모든 학교를 연결하는 경로가 없을 경우 -1을 출력해야한다. 최소 스패닝 트리에 추가된 edge수를 세서, v-1과 다르면 -1을 출력한다.
=> 크루스칼로 최소 스패닝 트리 만들면 결과는 edge의 수가 v-1과 같아야 하기 때문이다.
'''

import sys
input = sys.stdin.readline

# 특정 원소가 속한 집합을 찾기
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

univ = input().split()

# 모든 간선을 담을 리스트와 최종 비용을 담을 변수
edges = []
result = 0

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

# 모든 간선에 대한 정보를 입력받기
for _ in range(e):
    a, b, cost = map(int, input().split())
    if univ[a-1] == univ[b-1]:
        continue
    edges.append((cost, a, b))

# 간선을 비용순으로 정렬
edges.sort()

edge_cnt = 0
# 간선을 하나씩 확인하며
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost
        edge_cnt += 1
        

if edge_cnt != (v-1):
    print(-1)
else:
    print(result)