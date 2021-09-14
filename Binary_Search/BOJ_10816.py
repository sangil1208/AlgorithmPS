# 우선 탐색할 범위가 -10,000,000 <= x <= 10,000,000 이므로 이진 탐색 이용을 고려
# 이진 탐색을 위해서는 리스트가 정렬 되어 있어야 한다.
# 정렬 후 이진탐색 수행해도 시간초과 발생, counter 라이브러리 이용해서 해결

import sys
from collections import Counter

N = sys.stdin.readline().rstrip()
a = list(map(int, sys.stdin.readline().split()))
M = sys.stdin.readline().rstrip()
b = list(map(int, sys.stdin.readline().split()))

cnt = Counter(a)

for x in b:
    print(cnt[x], end=' ')
