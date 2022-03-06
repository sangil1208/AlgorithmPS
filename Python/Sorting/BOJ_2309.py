# 9개중 7개를 순서 상관 없이 고르는 경우의 수를 각각 오름차순 정렬한 후,
# 7개의 합이 100이 되면 해당 7개 숫자를 오름차순으로 출력하고 프로그램을 종료한다.

from itertools import combinations

a = []

for _ in range(9):
    a.append(int(input()))


for i in combinations(a, 7):
    sum = 0
    b = list(i)
    b.sort()
    for j in b:
        sum += j
    if sum == 100:
        for k in range(7):
            print(b[k])
        break
