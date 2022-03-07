from collections import deque

t = int(input())

moves = [(1, 0), (0, -1), (-1, 0), (0, 1)]
#상,하,좌,우 로 가능한 이동을 표현


def bfs(graph, i, j, visited, n, m):
    queue = deque()
    queue.extend([(i, j)])
    visited[i][j] = True
    while queue:
        v = queue.popleft()
        #cnt
        for move in moves:
            x = v[0] + move[0]
            y = v[1] + move[1]
            if x >= 0 and x < n and y >= 0 and y < m \
                    and int(graph[x][y]) == 1 and not visited[x][y]:
                queue.append((x, y))
                visited[x][y] = True


for _ in range(t):
    m, n, k = map(int, input().split())
    cnt = 0
    a = [[] for _ in range(k)]
    graph = [[0]*(m) for _ in range(n)]
    visited = [[False]*m for _ in range(n)]

    for _ in range(k):
        x, y = map(int, input().split())
        graph[y][x] = 1

    for i in range(n):
        for j in range(m):
            if int(graph[i][j]) == 1 and not visited[i][j]:
                bfs(graph, i, j, visited, n, m)
                cnt += 1
    print(cnt)
