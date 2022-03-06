# 플로이드 워셜 알고리즘을 이용해 풀었다. 맥주가 떨어지기 전에 도달할 수 있는 거리는 1을 저장하고, 도달할 수 없는 거리는 INF
# 이 상태에서 플로이드 워셜 알고리즘 적용하면, 도달 가능한 점은 INF보다 작을 것이고, 도달 불가능한 곳은 INF일 것이다.
# 시작점에서 도착점까지의 거리를 출력한다.

'''하지만 시간초과가 발생했는데, K, A, B 3중 반복문에서 min함수를 이용해 무조건 그래프의 값을 변경하는 것이 아닌
더 작은 값으로 갱신이 필요할때만 그래프의 값을 변경하는 방식으로 시간초과 문제를 해결했다.'''

import sys
input = sys.stdin.readline
INF = 1e9

t = int(input())

for _ in range(t):
    nodes = []
    n = int(input())
    graph = [[INF]*(n+2) for _ in range(n+2)]

    for _ in range(n+2):
        a, b = map(int, input().split())
        nodes.append((a, b))

    for a in range(n+2):
        for b in range(n+2):
            if a == b:
                continue
            dist = (
                abs(nodes[a][0]-nodes[b][0])+abs(nodes[a][1]-nodes[b][1]))

            if dist <= 1000:
                graph[a][b] = 1

    for k in range(n+2):
        for a in range(n+2):
            for b in range(n+2):
                if graph[a][b] > graph[a][k]+graph[k][b]:
                    graph[a][b] = graph[a][k]+graph[k][b]

    if 0 <= graph[0][n+1] < INF:
        print("happy")
    else:
        print("sad")


