# import sys
# input = sys.stdin.readline

# n, m = map(int, input().split())

# graph = []

# for _ in range(n):
#     graph.append(list(input().rstrip()))
    
# print(graph)
                 
import sys 
input = sys.stdin.readline

n = int(input())

num = list(map(int, input().split()))
res = 0

for i in range(n):
    cnt = 0
    for j in range(1, num[i]+1):
        if num[i]%j == 0:
            cnt += 1
    if cnt == 2:
        res+=1

print(res)
    
        
    
    