'''
DP 를 이용한다. 각 금액 별 최소 거스름돈 개수를 계산한다.
i-5를 이용해 계산해야 하므로 6부터 for문을 돌리고,
초기값으로 2와 5에 해당하는 거스름돈 최소값을 1로 설정해준다.
추가적으로 6미만 값들 중에서 4는 2원짜리 2개로 만들 수 있으므로 초기값에 설정해줬다.
for문 내의 첫번째 if문에서 2를 뺐을때 거슬러줄 수 있는 돈인지 확인하고, 
두 번째 if문에서 5를 뺐을때 거슬러 줄 수 있는 돈인지 확인한다.
'''

import sys
import math
input = sys.stdin.readline

n = int(input())
INF = math.inf

d = [INF]*100001

d[2] = 1
d[4] = 2
d[5] = 1

for i in range(6, n+1):
    if d[i-2]!=0:
        d[i] = d[i-2] + 1
    if d[i-5]!=0:
        d[i] = min(d[i], d[i-5] + 1)

if d[n] == INF:
    print(-1)
else:
    print(d[n])
    