'''
처음에 DP를 생각했지만 시간 제한 2초, bfs로 충분할 것으로 판단함.
2배, -1, 1에 대해 각각 cost +1을 시켜준다.
목적지가 x라면, x+1까지만 확인하면 x/2, x-1은 이전에 확인했을 것이므로 bfs를 종료한다.
'''

from collections import deque
import math

INF = math.inf


def bfs(graph, x, xf):
    q = deque([x])
    graph[x] = 0
    while q:
        dx = q.popleft()
        if 2*dx<=100000:
            if graph[2*dx] > graph[dx] + 1:
                graph[2*dx] = graph[dx] + 1
                q.append(2*dx)
        if dx+1<=100000: 
            if graph[dx+1] > graph[dx] + 1:
                graph[dx+1] = graph[dx] + 1
                q.append(dx+1)
        if dx-1>=0:
            if graph[dx-1] > graph[dx] + 1:
                graph[dx-1] = graph[dx] + 1
                q.append(dx-1)
        if dx == xf+1:
            break
    

        
         

n, k = map(int, input().split())

graph = [INF] * 100001

bfs(graph, n, k)
print(graph[k])
