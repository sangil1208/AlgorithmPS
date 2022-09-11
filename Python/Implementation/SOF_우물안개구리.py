n, m = map(int, input().split())
weight = list(map(int, input().split()))


relation = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    relation[a].append(b)
    relation[b].append(a)
    
cnt = 0

for i in range(1, n+1):
    if len(relation[i]) == 0:
        cnt += 1
    else:
        flag = 0
        for r in relation[i]:
            if weight[i-1] <= weight[r-1]:
                flag = 1
                break
        if flag == 0:
            cnt += 1

print(cnt)