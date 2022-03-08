# 서로소 집합 / Disjoint Sets
: 공통 원소가 없는 두 집합

- 서로소 집합 자료구조란 서로소 부분 집합들로 나누어진 원소들의 데이터를 처리하기 위한 자료구조
- 서로소 집합 자료구조는 합집합과 찾기 연산으로 구성
- union 연산 : 2개의, 원소가 포함된 집합을 하나의 집합으로 합치는 연산
- find 연산 : 특정한 원소가 속한 집합이 어떤 집합인지 알려주는 연산

### Union 연산 처리과정
1. union 연산을 확인하여, 서로 연결된 두 노드 A, B 를 확인한다.
 1) A와 B의 루트 노드 A' 과 B'를 각각 찾는다.
 2) A'을 B'의 부모 노드로 설정한다. (일반적으로, A'가 B'보다 작은 경우 이와 같이 설정)
2. 모든 union 연산을 처리할 때가지 1번 과정을 반복


## 서로소 집합 알고리즘 소스코드
```python
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

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

# union 연산을 각각 수행
for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent, a, b)

# 각 원소가 속한 집합 출력
print('각 원소가 속한 집합: ', end='')
for i in range(1, v+1):
    print(find_parent(parent, i), end=' ')

print()

# 부모 테이블 내용 출력
print('부모 테이블: ', end='')
for i in range(1, v+1):
    print(parent[i], end =' ')

```

# 서로소 집합을 활용한 사이클 판별
Union 연산은 그래프에서의 간선으로 표현될 수 있다. 따라서 간선을 하나씩 확인하면서,
두 노드가 포함되어 있는 집합을 합치는 과정을 반복하는 것만으로 사이클 판별 가능
1. 각 간선을 확인하며 두 노드의 루트 노드를 확인한다.
 1) 루트 노드가 서로 다르다면 두 노드에 대하여 union연산 수행
 2) 루트 노드가 서로 같다면 Cycle 발생
2. 그래프에 포함되어 있는 모든 간선에 대해 1번의 과정 반복

=> 이 알고리즘은 간선에 방향성이 없는 무향 그래프에서만 적용 가능

```python
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

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

cycle = False

for i in range(e):
    a, b = map(int ,input().split())
    if find_parent(parent, a) == find_parent(parent, b):
        cycle = True:
        break
    else:
        union_parent(parent, a, b)
```

# 신장 트리
하나의 그래프가 있을 때, 모든 노드를 포함하면서 사이클이 존재하지 않는 부분 그래프

# 크루스칼 알고리즘 (최소 신장 트리 알고리즘)
신장 트리 중에서, 최소 비용으로 만들 수 있는 신장 트리 찾는 알고리즘

- 그리디 알고리즘
- 모든 간선에 대해 정렬을 수행한 뒤, 가장 거리가 짧은 간선부터 집합에 포함시킴

1. 간선 데이터를 비용에 따라 오름차순 정렬
2. 간선을 하나씩 확인하며 현재의 간선이 사이클 발생시키는지 확인
 1) 사이클이 발생하지 않는 경우 최소 신장 트리에 포함
 2) 사이클이 발생하는 경우 최소 신장 트리에 포함시키지 않는다
3. 모든 간선에 대하여 2번의 과정을 반복

=> 최종적으로 신장 트리에 포함되는 간선의 개수는 노드개수-1 과 같다.
=> 최소 신장 트리에 포함되어 있는 간선의 비용을 모두 더하면, 그 값이 최종 비용에 해당

```python
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

# 모든 간선을 담을 리스트와 최종 비용을 담을 변수
edges = []
result = 0

# 부모 테이블상에서, 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

# 모든 간선에 대한 정보를 입력받기
for _ in range(e):
    a, b, cost = map(int, input().split())
    edges.append((cost, a, b))

# 간선을 비용순으로 정렬
edges.sort()

# 간선을 하나씩 확인하며
for edge in edges:
    cost, a, b = edge
    if find_parent(parent, a) != find_parent(parent, b):
        union_parent(parent, a, b)
        result += cost
```

## 크루스칼 알고리즘의 시간 복잡도
- 크루스칼 알고리즘은 간선의 개수가 E개일때, O(ElogE)의 시간 복잡도를 가진다.
- 크루스칼 알고리즘에서 가장 오래 걸리는 부분이 간선을 정렬하는 작업이기 때문
(E개의 데이터를 정렬 시 시간 복잡도가 O(ElogE))
- 크루스칼 내부에서 사용되는 서로소 집합 알고리즘의 시간 복잡도는 정렬 알고리즘의 복잡도보다 작으므로 무시한다.