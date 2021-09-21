# 기본적인 플로이드 워셜 알고리즘 사용하는 문제지만, 간선 입력으로 같은 쌍에 대한 다른 값이 중복으로 들어올 수 있다.
# 예를 들어, (3, 4, 1) 이후에 (3, 4, 2) 가 들어온다면, 1이 더 작으므로 이후에 들어온 입력 값은 무시하도록 짜야 한다. (line 21~25)

import sys
input = sys.stdin.readline

INF = int(1e9)

n = int(input())
m = int(input())

graph = [[INF]*(n+1) for _ in range(n+1)]

# 자기 자신에서 자기 자신으로 가는 비용 0으로 초기화
for a in range(1, n+1):
    for b in range(1, n+1):
        if a == b:
            graph[a][b] = 0

# 각 간선에 대한 정보 입력
for _ in range(m):
    a, b, c = map(int, input().split())
    if graph[a][b] < c:
        continue
    graph[a][b] = c
    
# FW 알고리즘 수행
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            graph[a][b] = min(graph[a][b], graph[a][k]+graph[k][b])

# 결과 출력
for a in range(1, n+1):
    for b in range(1, n+1):
        if graph[a][b] == INF:
            print("0", end=' ')
        else:
            print(graph[a][b], end=' ')
    print()