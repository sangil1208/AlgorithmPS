
k = int(input())
result = []

for _ in range(k):
    i = int(input())
    if i == 0:
        result.pop()
    else:
        result.append(i)


print(sum(result))