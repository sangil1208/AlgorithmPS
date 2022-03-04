'''
물건 간 무게 비교가 가능한 경우는 모순이 없이 주어지고,
6>5, 5>4이면 6>4를 비교할 수 있다.
모든 점 사이의 거리를 INF로 초기화 해 놓고, 비교가 가능한 경우 1을 저장한다.
이후 플로이드 워셜 알고리즘을 통해 다른 점을 거쳐서 갈 수 있는 점(다른 숫자와 비교해서 간점 비교 결과 알 수 있는 숫자)를 찾는다.
각 숫자 별 다른 숫자와 비교 가능한 경우는 리스트에 정수가 저장될 것이므로, 각 리스트에서 INF의 수를 출력한다.
2>3 인 경우 graph[2][3]에 2가 3보다 크다는 의미로 1을 저장한다 / 2<3인 경우 graph[2][3]에 2가 3보다 작다는 의미로 -1을 저장한다.
3<2 이고, 2<1 인 경우와 같이 연쇄적으로 작거나, 3>2이고 2>1인 경우와 같이 연쇄적으로 큰 비교가 가능한 경우 3과 1을 비교할 수 있다.
따라서 graph[a][k], graph[k][b] 가 모두 양수인 경우 혹은 모두 음수인 경우 비교 가능하다. 이 경우 최단거리를 갱신해준다.
결과적으로 비교가 가능한 숫자들에 해당하는 graph에는 음수 혹은 양수의 정수가 저장되어 있을 것이다. 자기 자신과는 항상 비교가 가능하므로 0을 저장한다.
각 숫자에 해당하는 graph에서 INF가 있는(비교가 불가능한 수) 개수를 출력한다.
-> 이 문제는 주어지는 n,m의 최대값이 적어서 python3로도 통과했음
'''

import sys
INF = int(1e9)
input = sys.stdin.readline

n = int(input())
m = int(input())

graph = [[INF]*(n+1) for _ in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = -1
    
for a in range(1, n+1):
    for b in range(1, n+1):
        if a==b:
            graph[a][b] = 0
        
for k in range(1, n+1):
    for a in range(1, n+1):
        for b in range(1, n+1):
            if (graph[a][k]>0 and graph[k][b]>0) or (graph[a][k]<0 and graph[k][b]<0):
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b])
            
cnt = [0]*(n+1)

for i in range(1, n+1):
    for j in range(1, n+1):
        if graph[i][j] == INF:
            cnt[i]+=1
    print(cnt[i])

