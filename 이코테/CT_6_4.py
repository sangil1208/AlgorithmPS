N, K = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort(reverse = True)

print(a)
print(b)

for i in range(K):
    if a[i] > b[i]:
        a[i], b[i] = b[i], a[i]
    else:
        pass
    
print(sum(a))