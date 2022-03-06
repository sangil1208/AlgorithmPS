'''
a가 b보다 먼저 일어난 사건이면 graph[a][b]에 -1저장, graph[b][a]에 1저장
이후 플로이드 워셜 알고리즘을 수행하는데, graph[a][k], graph[k][b]가 둘다 음수이거나 둘다 양수인 경우에만 경로를 갱신한다.
이는 a<k, k<b 이면 a<b 비교가 성립하고, a>k, k>b 이면 a>b비교가 성립하기 때문이다. a<k, k>b인 경우는 a와 b의 대소 비교가 불가능하다.
BOJ_10159번 문제와 유사한 개념. 하지만 입력 개수가 50000개 이하로 10159에 비해 많다. pypy3로 제출해야 통과.
'''
import sys
INF = int(1e9)
input = sys.stdin.readline

n, m = map(int, input().split())

graph = [[INF]*(n+1) for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a][b] = -1 #a가 b보다 먼저 일어남
    graph[b][a] = 1 #b는 a보다 나중에 일어남

#자기 자신과의 비교를 0으로 저장하고, 비교 불가는 INF로 남도록 해서 INF이면 유추할 수 없는것으로 판단
for a in range(1, n+1):
    for b in range(1, n+1):
        if a==b:
            graph[a][b] = 0
        
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            if (graph[a][k]<0 and graph[k][b]<0) or (graph[a][k]>0 and graph[k][b]>0):
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])

s = int(input())

for i in range(s):
    a, b = map(int, input().split())
    if graph[a][b] == INF:
        print(0)
    elif graph[a][b] < 0:
        print(-1)
    else:
        print(1)