from collections import deque

moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]

def bfs(graph, visited, x, y):
    q = deque([(x, y)])
    visited[x][y] = True
    cnt = 1
    while q:
        v = q.popleft()
        for move in moves:
            nx = v[0] + move[0]
            ny = v[1] + move[1]
            if nx >= 0 and nx<n and ny>=0 and ny<n:
                if graph[nx][ny] == 1 and visited[nx][ny] == 0:
                    q.append((nx, ny))
                    visited[nx][ny] = 1
                    cnt += 1
                    
    cnt_list.append(cnt)

n = int(input())

graph = []

for _ in range(n):
    graph.append(list(map(int, input())))
    
visited = [[0]*n for _ in range(n)]

obs_cnt = 0
cnt_list = []

for i in range(n):
    for j in range(n):
        if graph[i][j] ==1 and visited[i][j] == 0:
            bfs(graph, visited, i, j)
            obs_cnt += 1
            
print(obs_cnt)
cnt_list.sort()
for c in cnt_list:
    print(c)