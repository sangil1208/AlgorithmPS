'''
이 문제는 첫 구현때 시간초과 발생.
초기 graph에 1으로 표시된 값부터 bfs를 모두 수행하도록 구현했다.
첫 1로 표시된 값부터 갈 수 있는 모든 곳을 bfs로 탐색하면서 1씩 숫자를 증가시키고, (걸린 시간을 의미)
다음 1로 표시된 값부터 갈 수 있는 모든 곳을 bfs로 탐색하면서 1씩 숫자를 증가시킨 값이 graph에 저장되어 있는 값보다 작은 경우에만 갱신하도록 구현했다.
이렇게 구현하면 graph가 꽉 찬 경우에도 bfs를 계속 수행해야 해서 시간 초과 발생

==> 한 시간 단위씩, graph가 1인 값부터 bfs를 수행하는것으로 해결했다.
1시간단위마다, 큐에 있는 값 각각에 대해 bfs를 수행한다.
또한, 값 갱신은 graph 값이 0일때만 진행하므로 0이 한번씩 다 다른 값으로 채워진 이후 (토마토가 모두 익은 이후) 부터는 값 갱신이 없다.
따라서 값 갱신을 계속 수행하는 첫 구현 방법에 비해 시간 소요가 적다.
'''


import sys
from collections import deque

input = sys.stdin.readline

m, n = map(int, input().split())
graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))
    
moves = [(0, -1), (0, 1), (1, 0), (-1, 0)]

def bfs(graph):
    while queue:
        for _ in range(len(queue)):
            x, y = queue.popleft()
            for move in moves:
                dx = x + move[0]
                dy = y + move[1]
                if 0<=dx<n and 0<=dy<m and graph[dx][dy] == 0:
                    graph[dx][dy] = graph[x][y] + 1
                    queue.append((dx, dy))
                                    
cnt = 0
start = []
queue = deque()
     
for a in range(n):
    for b in range(m):
        if graph[a][b] == 1:
            queue.append((a, b))
        if graph[a][b] != 0:
            cnt += 1

if cnt == (m*n):
    print(0)
    sys.exit(0)

bfs(graph)
    
cost = []
for a in range(n):
    for b in range(m):
        if graph[a][b] == 0:
            print(-1)
            sys.exit(0)
        cost.append(graph[a][b])

print(max(cost)-1)