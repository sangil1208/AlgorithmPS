# 랜선의 가능한 길이로 매우 큰 수가 입력되었기 때문에, 이진 탐색을 이용하는 방법을 떠올릴 수 있다.
# 입력받은 랜선 길이의 최대값을 end로 설정 후, start는 랜선의 길이를 0으로 자를 수 없기 때문에 1로 설정하고 이진탐색
# N개보다 많이 만드는 것도 N개를 만드는 것에 포함되고, 최대 랜선의 길이를 구해야 한다.
# 따라서 특정 수로 만들 수 있는 랜선의 개수가 N보다 크면, 탐색 범위를 오른쪽으로(증가) 이동한다.
# 위의 로직을 따르면 N개 이상을 만들 수 있는 수 중에서 최대값을 결과로 얻을 수 있다.

k, n = map(int, input().split())
lans = []

for _ in range(k):
    lans.append(int(input()))

start = 1
end = max(lans)
result = 0

while start <= end:
    cnt = 0
    mid = (start + end)//2
    for lan in lans:
        cnt += lan//mid
    if cnt < n:
        end = mid - 1
    else:
        result = mid
        start = mid + 1

print(result)
