# 사전 순으로 먼저 정렬 후, 길이가 짧은 순으로 정렬한다. 짧은 순 정렬은 선택 정렬을 이용했다.
# 하지만 n이 커서 시간 복잡도가 O(n^2) 인 선택 정렬을 사용하면 시간초과 발생.
# 따라서 O(NlogN) 을 보장하는 파이썬 라이브러리를 이용하여 정렬.
# 라이브러리 말고 퀵 정렬 알고리즘을 이용하면 시간초과 안나는지 직접 해보기

import sys

n = int(input())

a = []
for _ in range(n):
    a.append(sys.stdin.readline().rstrip())

a = list(set(a))  # 중복된 값을 제거해주기 위해 집합 자료형으로 변경 후 다시 리스트로 변경

a.sort()
a.sort(key=len)

'''for i in range(len(a)):
    min_index = i
    for j in range(i+1, len(a)):
        if len(a[j]) < len(a[min_index]):
            min_index = j
    a[i], a[min_index] = a[min_index], a[i]'''

for i in range(len(a)):
    print(a[i])

