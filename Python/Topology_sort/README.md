# 위상 정렬 / Topology Sort

위상 정렬은 순서가 정해져 있는 일련의 작업을 차례대로 수행해야 할 때 사용할 수 있는 알고리즘이다.
=> 방향 그래프의 모든 노드를 '방향성에 거스르지 않도록 순서대로 나열하는 것' 이다.

## 위상 정렬 알고리즘 수행과정
1. 진입차수가 0인 노드를 큐에 넣는다.
2. 큐가 빌 때까지 다음의 과정을 반복한다.
 1) 큐에서 원소를 꺼내 해당 노드에서 출발하는 간선을 그래프에서 제거한다.
 2) 새롭게 진입차수가 0이 된 노드를 큐에 넣는다.

- 이때, 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재한다고 판단한다. 우선 사이클이 발생하지 않는 경우만 고려해 위상정렬 공부
- 한 단계에서 큐에 새롭게 들어가는 원소가 2개 이상인 경우가 있다면, 위상 정렬의 답은 여러 가지가 될 수 있다.
- 위상 정렬을 수행할 때는 차례대로 모든 노드를 확인하면서, 해당 노드에서 출발하는 간선을 차례로 제거해야한다. 결과적으로 노드와 간선 모두 확인 필요
=> 시간 복잡도가 O(V+E)이다.

## 위상 정렬 코드
```python
from collections import deque

# 노드의 개수와 간선의 개수를 입력받기
v, e = map(int, input().split())
# 모든 노드에 대한 진입차수는 0으로 초기화
indegree = [0] * (v+1)
# 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트(그래프) 초기화
graph = [[] for i in range(v+1)]

# 방향 그래프의 모든 간선 정보를 입력받기
for _ in range(e):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b]+=1

# 위상 정렬 함수
def top_sort():
    result = [] # 알고리즘 수행 결과를 담을 리스트
    q = deque() 

    # 처음 시작할 대는 진입차수가 0인 노드를 큐에 삽입
    for i in range(1, v+1):
        if indegree[i] == 0:
            q.append(i)
    
    # 큐가 빌 때까지 반복
    while q:
        # 큐에서 원소 꺼내기
        now = q.popleft()
        result.append(now)
        # 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for i in graph[now]:
            indegree[i]-=1
            # 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if indegree[i] == 0:
                q.append(i)
    
    # 위상 정렬 수행 결과 출력
    for i in result:
        print(i, end=' ')

top_sort()

```