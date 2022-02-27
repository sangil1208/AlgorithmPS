from collections import deque


N, M = map(int, input().split())

graph = []

for i in range(N):
    graph.append(list(map(int, input())))

moves = [(1,0),(-1,0),(0,1),(0,-1)]

def bfs(x, y, graph):
    q = deque()
    q.append((x,y))
    
    while q:
        x,y = q.popleft()
        for move in moves:
            dx = x + move[0]
            dy = y + move[1]
            if (0<=dx and dx<N) and (0<=dy and dy<M) and graph[dx][dy]==1:
                graph[dx][dy] = graph[x][y] + 1
                q.append((dx,dy))

bfs(0, 0, graph)
print(graph)