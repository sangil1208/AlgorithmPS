'''
N, M 최대값이 50이므로, N^3 (6,250,000) 까지는 OK (1초 -> 2천만) => 브루트 포스로 해결

1.체스판을 칠하는 두 가지뿐인 경우의 수를 미리 정의해준다.
2.체스판의 범위를 넘지 않는 범위에서, 입력된 체스판을 8*8 크기로 자른다.
3.미리 정의된 체스판과 자른 체스판을 비교한다.
4.비교해서 다른 개수를 count한다.
5.최종적으로, 모든 가능한 자른 체스판에 대해 미리 정의된 체스판과의 차이 중 최솟값이 정답이다.

'''


import sys
input = sys.stdin.readline

n, m = map(int, input().split())

line1 = ['W', 'B', 'W', 'B', 'W', 'B', 'W', 'B']
line2 = ['B', 'W', 'B', 'W', 'B', 'W', 'B', 'W']

sample1 = []
sample2 = []

for i in range(4):
    sample1.append(line1)
    sample1.append(line2)
    sample2.append(line2)
    sample2.append(line1)

def cal_diff(sample1, sample2, graph):
    diff = 0
    diff_list = []
    for a in range(8):
        for b in range(8):
            if sample1[a][b] != graph[a][b]:
                diff += 1
    diff_list.append(diff)
    
    diff = 0
    for a in range(8):
        for b in range(8):
            if sample2[a][b] != graph[a][b]:
                diff += 1
    diff_list.append(diff)
    
    return min(diff_list)

graph = []

for _ in range(n):
    graph.append(list(input().rstrip()))

res = []

for a in range(n):
    for b in range(m):
        if a+7 < n and b+7 < m:
            temp = []
            for i in range(a, a+8):
                row = graph[i]
                temp.append(row[b:b+8])
            res.append(cal_diff(sample1, sample2, temp))
                
print(min(res))

                

    