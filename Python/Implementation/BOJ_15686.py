'''
itertools 사용해서 치킨집 좌표를 하나씩 고르면, ((x,y),) 와 같은 형태로 선택되어 처리하기 곤란하다.
따라서, 남겨둘 치킨집을 1개만 고른 경우는 따로 치킨집과 모든 집 사이의 거리를 계산해서 더한 값을 계산해 먼저 처리한다.
이후 남겨둘 치킨집이 2 이상이라면, itertools로 조합을 생성하고,
치킨집에 대해 모든 집과의 거리를 계산해서 더한 값을 distlist에 추가한다.
이때, 2개 이상 치킨집을 골랐을 때, 특정 집과 치킨집의 거리는 각각의 골라진 치킨집과 특정 집과의 거리의 최솟값으로 처리해야한다.
'''

from itertools import combinations
import math

MAX = math.inf
n, m = map(int, input().split())

graph = []
home = []
chicken = []
iterlist = []
distlist = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

for i in range(n):
    for j in range(n):    
        if graph[i][j] == 1:
            home.append((i, j))
        if graph[i][j] == 2:
            chicken.append((i, j))
            
# 1개 골랐을때 거리
for i in chicken:
    sumdist = 0
    for j in home:
        sumdist += abs(i[0]-j[0]) + abs(i[1]-j[1])
    distlist.append(sumdist)
    
if m==1:
    print(min(distlist))
    
else:
    for i in range(2, m+1):
        for c in combinations(chicken, i):
            iterlist.append(c)

    for i in iterlist:
        sumdist = 0
        for h in home:
            mindist = MAX
            for j in range(len(i)):
                if abs(h[0]-i[j][0]) + abs(h[1]-i[j][1]) < mindist:
                    mindist = abs(h[0]-i[j][0]) + abs(h[1]-i[j][1])
            sumdist += mindist
                
        distlist.append(sumdist)
    
    print(min(distlist))
            

    
    
    