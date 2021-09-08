from collections import deque


def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    while queue:
        v = queue.popleft()
        print(v, end=' ')
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


def dfs(graph, v, visited):
    visited[v] = True
    print(v, end=' ')
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)


#dfs함수는 재귀를 이용하고, bfs는 deque라이브러리를 이용해서 구현했다.
#재귀로 dfs를 구현했기 때문에 dfs보다 bfs구현이 조금 더 빠르게 동작한다 

n, m, v = map(int, input().split())
graph = [[] for _ in range(n+1)]
visited = [False]*(n+1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

#각 노드와 연결된 노드 정보를 입력하는데, 양방향 그래프이므로 양방향으로 정보 입력

for i in range(1,n+1):
    graph[i].sort()

# 방문 가능한 정점이 여러 개 이므로 정점 번호가 작은 것을 먼저 방문한다

dfs(graph, v, visited)
visited = [False]*(n+1)
#dfs이후 visited를 다시 초기화 한 후 bfs진행
print()
bfs(graph, v, visited)

    