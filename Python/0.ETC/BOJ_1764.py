'''
순차 탐색은 시간초과 발생 -> 해시 이용한 탐색 -> 파이썬에선 딕셔너리 자료형 이용.
get(x, 0) 은 key x에 해당하는 value를 가져오는데, 저장된 value가 없으면 default 0을 반환하는 함수이다.
'''

import sys
input = sys.stdin.readline


n ,m = map(int, input().split())
a = []
b = []

total = []

res_dict = dict()

for _ in range(n):
    tmp = input().rstrip()
    res_dict[tmp] = res_dict.get(tmp, 0) + 1
    total.append(tmp)
    
for _ in range(m):
    tmp = input().rstrip()
    res_dict[tmp] = res_dict.get(tmp, 0) + 1
    total.append(tmp)
    
total = list(set(total))

res = []
cnt = 0

for name in total:
    if res_dict[name] == 2:
        cnt += 1
        res.append(name)
        
print(cnt)
res.sort()
for i in range(len(res)):
    print(res[i])