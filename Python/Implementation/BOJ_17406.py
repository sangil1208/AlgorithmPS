'''
python3으로 제출 시 시간초과 발생. deepcopy 사용하지 않고 해보기(deep copy가 시간 효율 별로)
pypy3로 하면 맞음
'''

import itertools
import copy

def calc_min_arr(arr):
    min = int(1e9)
    for i in range(n):
        sum = 0
        for j in range(m):
            sum += arr[i][j]
        if sum<min:
            min = sum
    
    return min
    
def rotate_temp(temp, start, end):
    for a in range(start[0], end[0]+1):
        if (a>start[0] and a<end[0]):
            continue
        if a==start[0]:
            for i in range(start[1]+1, end[1]+1):
                temp[a][i] = graph_temp[a][i-1]
        if a==end[0]:
            for i in range(start[1], end[1]):
                temp[a][i] = graph_temp[a][i+1]
    
        
    for b in range(start[1], end[1]+1):
        if (b>start[1] and b<end[1]):
            continue
        if b==start[1]:
            for i in range(start[0], end[0]):
                temp[i][b] = graph_temp[i+1][b]
        if b==end[1]:
            for i in range(start[0]+1, end[0]+1):
                temp[i][b] = graph_temp[i-1][b]
    

if __name__ == "__main__":
    
    n, m, k = map(int, input().split())

    graph = []
    rot = []
    arr_range = []
    result = int(1e9)

    for _ in range(n):
        graph.append(list(map(int, input().split())))
        
    for _ in range(k):
        r, c, s = map(int, input().split())
        rot.append([r, c, s])
        arr_range.append([(r-s-1, c-s-1), (r+s-1, c+s-1)])
    
    perm = itertools.permutations(arr_range, k)
    
    for p in perm:
        temp = copy.deepcopy(graph)
        arr_range_temp = p
        graph_temp = graph
        for i in range(len(arr_range_temp)):
            start = arr_range_temp[i][0]
            end = arr_range_temp[i][1]
            while True:
                if start[0] == end[0] and start[1] == end[1]:
                    break
                rotate_temp(temp, start, end)
                start = (start[0]+1, start[1]+1)
                end = (end[0]-1, end[1]-1)
            
            graph_temp = copy.deepcopy(temp)
            
        temp_sum = calc_min_arr(temp)
        if temp_sum < result:
            result = temp_sum
            
            
    print(result)