N, M = map(int, input().split())
arr = list(map(int, input().split()))

start = 0
end = max(arr)

result = 0

while start <= end:
    mid = (start+end)//2
    sum = 0
    for a in arr:
        if a-mid > 0:
            sum = sum + (a - mid)
    if sum >= M:
        result = mid
        start = mid + 1
    else:
        end = mid - 1


print(result)