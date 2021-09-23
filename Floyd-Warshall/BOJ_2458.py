# 2차원 리스트 좌표 [x][y]에 1을 저장한다. x,y는 입력값으로 x가y보다 작다는 의미이다.
# 플로이드 워셜 알고리즘으로 갈 수 있는 모든 좌표를 구한다. (거리가 inf가 아니면 갈 수 있는 좌표이다)
# 갈 수 없는 좌표라면 반대로 해당 좌표에서 자신의 좌표까지의 경로가 존재하는지 확인하고 있다면 경로가 있음으로 표시한다.
# 그래프의 열마다 합계를 구해 합계가 INF미만이면 해당 열의 노드에서 모든 노드와 대소비교가 가능 하다는 의미이므로 CNT를 1증가시킨다.
# 다른 모든 노드들과 대소비교가 가능한 노드의 횟수인 CNT를 출력한다.
# pypy3으로 컴파일 해야 시간 내에 통과한다. n^3의 시간복잡도를 가지는데 이 부분을 어떻게 개선해야 python3로도 통과할까?

import sys
input = sys.stdin.readline

n, m = map(int, input().split())
INF = 1e9
cnt = 0

graph = [[INF]*(n) for _ in range(n)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1

for a in range(n):
    for b in range(n):
        if a == b:
            graph[a][b] = 0

for k in range(n):
    for a in range(n):
        for b in range(n):
            if graph[a][b] > graph[a][k] + graph[k][b]:
                graph[a][b] = graph[a][k] + graph[k][b]

for a in range(n):
    for b in range(n):
        if graph[a][b] == INF and graph[b][a]!= INF:
            graph[a][b] = 1

for i in range(n):
    if sum(graph[i]) < INF:
        cnt += 1
        
print(cnt)
