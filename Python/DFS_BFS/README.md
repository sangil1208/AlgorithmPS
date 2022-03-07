# DFS
- 그래프에서 깊은 부분을 우선적으로 탐색
- Stack 사용 -> 기본 리스트에서 append()와 pop() 메서드 사용하면 스택 자료구조와 동일하게 동작
- 탐색 수행에 O(N) 시간 소요
- Stack을 사용하므로 재귀함수를 이용하면 구현이 간단

동작 과정
1. 탐색 시작 노드를 스택에 삽입하고 방문 처리를 한다.
2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 인접 노들르 스택에 넣고 방문 처리를 한다. 방문하지 않은 인접 노드가 없으면 스택에서 최상단 노드를 꺼낸다.
3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.

## Base Code 

```python

#graph는 2차원 list
visited = [False] * 9

def dfs(graph, v, visited):
    # 현재 노드를 방문 처리
    visited[v] = True
    print(v, end=' ')
    # 현재 노드와 연결된 다른 노드를 재귀적으로 방문
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)

```

# BFS
- 가까운 노드부터 탐색
- Queue 사용 (deque 라이브러리 사용)
- 탐색 수행에 O(N) 시간 소요
- 일반적으로 수행 시간 DFS보다 좋으며, 코테에서 DFS보다는 BFS구현이 조금 더 빠르다.

동작 과정
1. 탐색 시작 노드를 큐에 삽입하고 방문 처리를 한다.
2. 큐에서 노드를 꺼내 해당 노드의 인접 노드 중에서 방문하지 않은 노드를 모두 큐에 삽입하고 방문 처리를 한다.
3. 2번의 과정을 더 이상 수행할 수 없을 때까지 반복한다.

## Base Code 

```python

from collections import deque
#graph는 2차원 list
visited = [False] * 9

def bfs(graph, start, visited):
    queue = deque([start])
    # 현재 노드를 방문 처리
    visited[start] = True
    # 큐가 빌 때까지 반복
    while queue:
        # 큐에서 하나의 원소를 뽑아 출력
        v = queue.popleft()
        print(v, end=' ')
        # 해당 원소와 연결된, 아직 방문하지 않은 원소들을 큐에 삽입
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
```