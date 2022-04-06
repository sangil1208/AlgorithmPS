'''
기본적인 bfs문제인데, 층이 존재하므로 3차원으로 리스트를 구성하는 것만 변경된 문제
'''


from collections import deque
import math

INF = math.inf
moves = [(0, 0, 1), (0, 0, -1), (0, 1, 0), (0, -1, 0), (1, 0, 0), (-1, 0, 0)]


def bfs(z, x, y):
    q = deque([(z, x, y)])
    while q:
        v = q.popleft()
        for move in moves:
            dz = v[0] + move[0]
            dx = v[1] + move[1]
            dy = v[2] + move[2]
            if 0<=dz<l and 0<=dx<r and 0<=dy<c and graph[dz][dx][dy] == '.':
                if dist[v[0]][v[1]][v[2]] + 1 < dist[dz][dx][dy]:
                    dist[dz][dx][dy] = dist[v[0]][v[1]][v[2]] + 1
                    q.append((dz, dx, dy))
            

while True:
    start = []
    dest = []
    l, r, c = map(int, input().split())
    if l==0 and r==0 and c==0:
        break

    graph = [[] for _ in range(l)]
    dist = [[[INF]*c for _ in range(r)] for _ in range(l)]

    for i in range(l):
        for _ in range(r):
            graph[i].append(list(input().rstrip()))
        input()

    for i in range(l):
        for j in range(r):
            for k in range(c):
                if graph[i][j][k] == 'E':
                    dest = [i, j, k]
                    graph[i][j][k] = '.'
                if graph[i][j][k] == 'S':
                    start = [i, j, k]
                    
    dist[start[0]][start[1]][start[2]] = 0
    
    bfs(start[0], start[1], start[2])
    
    
    if dist[dest[0]][dest[1]][dest[2]] == INF:
        print('Trapped!')
    else:
        print('Escaped in ' + str(dist[dest[0]][dest[1]][dest[2]]) + ' minute(s).')

    
    

        