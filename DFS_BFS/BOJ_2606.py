from collections import deque

'''def bfs(graph, start, visited):
    queue = deque([start])
    visited[start] = True
    cnt = -1
    while queue:
        v = queue.popleft()
        cnt += 1
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
    return cnt '''

cnt = -1

def dfs(graph, v, visited):
    visited[v] = True
    global cnt
    cnt += 1 
    for i in graph[v]:
        if not visited[i]:
            dfs(graph, i, visited)
    return cnt


n = int(input())
m = int(input())
graph = [[] for _ in range(n+1)]
visited = [False]*(n+1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

#각 노드와 연결된 노드 정보를 입력하는데, 양방향 그래프이므로 양방향으로 정보 입력

for i in range(1,n+1):
    graph[i].sort()

print(dfs(graph, 1, visited))
