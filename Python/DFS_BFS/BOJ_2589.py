'''
1. 지도가 최대 50*50이고, 모든 지역에서 bfs를 수행한다고 쳐도 2500*2500으로 2000만을 안넘으니 bfs사용한 브루트포스 구현
2. 지도 입력 받은 후. 땅으로 표시된 좌표를 따로 저장
3. 땅으로 표시된 좌표에서 각각 bfs를 수행하며 다른 땅으로 가는 거리들 저장
4. 저장된 거리들 중 최댓값 출력

pypy3로 제출한 문제
'''


from collections import deque
import math

INF = math.inf
n, m = map(int, input().split())
moves = [(0,1), (0,-1), (1,0), (-1,0)]
graph = []

for _ in range(n):
    graph.append(list(input().rstrip()))
    
lands = []

final = []

for i in range(n):
    for j in range(m):
        if graph[i][j] == 'L':
            lands.append((i, j))

def bfs(x, y):
    q = deque([(x, y)])
    while q:
        v = q.popleft()
        for move in moves:
            dx = move[0] + v[0]
            dy = move[1] + v[1]
            if 0<=dx<n and 0<=dy<m and graph[dx][dy] == 'L' and dist[v[0]][v[1]]+1 < dist[dx][dy]:
                dist[dx][dy] = dist[v[0]][v[1]]+1
                q.append((dx, dy))
            
for land in lands:
    dist = [[INF]*m for _ in range(n)]
    x, y = land[0], land[1]
    dist[x][y] = 0
    bfs(x, y)
    for i in range(n):
        for j in range(m):
            if dist[i][j] != INF:
                final.append(dist[i][j])

print(max(final))