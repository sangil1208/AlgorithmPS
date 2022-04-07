'''
1000이 최대 입력이므로, 1000개 각각 숫자에 대해 bfs를 수행해도 1000*1000 이므로 1초안에 수행 가능

1. 하나 삭제 시 1초 소요
2. 붙여넣기 시, 첫 붙여넣기는 2초, 이후 붙여넣기는 1초 소요
3. 2번 구현을 위해 모든 숫자마다 bfs 수행하면서, 각 bfs에서 첫 붙여넣기 수행 시에만 2초 증가시키고, 이후 붙여넣기는 1 증가시키도록 구현
4. 갱신할 값이 이미 최솟값이더라도, 해당 값의 배수 값들도 검사해야 하므로 갱신할값 == 이미 있는 값인 경우에도 q에 append하는부분 추가해서 정답
(if v == start and graph[v] + 2 <= graph[dv], elif v!=start and graph[v] + 1 <= graph[dv]) 이부분에 등호 추가 
'''

from collections import deque
import math

INF = math.inf
s = int(input())

graph = [INF] * 1001
graph[1] = 0

def bfs(start, clip):
    q = deque([start])
    while q:
        v = q.popleft()
        dv = v-1
        if 1<=dv<=1001 and graph[v] + 1 < graph[dv]:
            graph[dv] = graph[v] + 1
            q.append(dv)
        dv = v + clip
        if 1<=dv<1001:
            if v == start and graph[v] + 2 <= graph[dv]:
                graph[dv] = graph[v]+  2
                q.append(dv)
            elif v!=start and graph[v] + 1 <= graph[dv]:
                graph[dv] = graph[v] + 1
                q.append(dv)

for i in range(1, s+1):
    clip = i
    bfs(i, clip)

print(graph[s])

