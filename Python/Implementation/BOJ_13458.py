n = int(input())
graph = []
res = 0

graph = list(map(int, input().split()))
    
b, c = map(int, input().split())

for i in range(n):
    if graph[i] > 0:
        graph[i] -= b
        res += 1
    if graph[i] > 0:
        if graph[i]%c == 0: 
            res += graph[i]//c   
        else:
            res += graph[i]//c+1
print(res)