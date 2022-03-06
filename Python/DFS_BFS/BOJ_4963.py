'''
섬이라고 표시된 곳부터 시작해서, 해당 지점과 이어진 섬을 모두 탐색한다.
위 과정 1회당 1개의 붙어있는 섬을 찾은 것이다.
dfs로 풀면 setrecursionlimit으로 재귀 호출 제한을 늘려줘야 한다.
BOJ의 채점 서버에서 이 값은 디폴트 1,000으로 되어 있기 때문
=> 재귀 호출 제한을 변경하거나, bfs로 풀면 해결
'''

import sys
sys.setrecursionlimit(10**6)

input = sys.stdin.readline

moves = [(-1, 0),(1, 0),(0, 1),(0, -1),(1, 1),(1, -1),(-1, -1),(-1, 1)]

def dfs(graph, x, y, visited):
    visited[x][y] = True
    for move in moves:
        dx = x+move[0]
        dy = y+move[1]
        if 0<=dx<h and 0<=dy<w:
            if graph[dx][dy] == 1 and (not visited[dx][dy]):
                dfs(graph, dx, dy, visited)
            
while(True):
    island = 0
    
    w, h = map(int, input().split())
    if w==0 and h==0:
        break
    graph = []
    visited = [[False]*(w) for _ in range(h)]
    for i in range(h):
        graph.append(list(map(int, input().split())))
    
    for a in range(h):
        for b in range(w):
            if graph[a][b] == 1 and visited[a][b] == False:
                dfs(graph, a, b, visited)
                island+=1
    
    print(island)
    