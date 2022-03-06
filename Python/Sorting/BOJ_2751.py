# 2750번은 n = 1000 이었지만, 이번 문제는 n이 1000000으로, 파이썬 정렬 라이브러리를 이용하면 시간 초과 발생한다.
# 따라서 가장 큰 수와 작은 수의 차이가 1000000이하일때 효율적으로 사용 가능한 계수정렬을 이용한다.
# 계수정렬의 시간복잡도는 O(N+K) 이다. 모든 데이터가 양의 정수인 상황에서 데이터의 개수가 N, 데이터중 최대값이 K

# 파이썬 정렬 라이브러리를 사용해서가 아닌 input을 sys.stdin.readline() 으로 받지 않아서 시간 초과
# 수행 시간을 줄이기 위해 sys 라이브러리를 사용해 input과 output모두 수행

import sys


n = int(input())
a = []

for _ in range(n):
    a.append(int(sys.stdin.readline().rstrip()))

a.sort()

for i in range(n):
    # sys.stdout.write(str(a[i])+'\n')
    print(a[i])

