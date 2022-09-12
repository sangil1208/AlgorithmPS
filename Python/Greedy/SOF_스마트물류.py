import sys

input = sys.stdin.readline

n, k = map(int, input().split())

graph = list(input().rstrip())

result_1 = 0

for i in range(n):
    if graph[i] == 'H':
        flag = 0
        for j in range(k-1, -1, -1):
            if (i-j-1)>=0 and graph[i-j-1] == 'P':
                result_1 += 1
                graph[i-j-1] = 'Q'
                flag = 1
                break
        if flag == 0:
            for j in range(k):
                if (i+j+1)<n and graph[i+j+1] == 'P':
                    result_1 += 1
                    graph[i+j+1] = 'Q'
                    break

print(result_1)