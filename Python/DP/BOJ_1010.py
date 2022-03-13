'''
n = 2, m =5 인 경우에 겹치지 않게 지으려면
5개중에 2점을 선택한다고 생각하고, 해당 점이 (n=1, m=1), (n=2, m=2) 와 같이 오름차순 정렬 되있는 경우면 겹치지 않는다.
(n=1, m=2), (n=2, m=1) 인 경우는 다리가 겹치게 된다. 따라서 순열이 아닌 조합을 사용해야 한다. 
nPr = n!/(n-r)!
nCr = n!/(n-r)!*r!
또한 시간 제한이 매우 짧으므로, 팩토리얼 계산 시 dp 사용
'''

import sys
import itertools

input = sys.stdin.readline

def fact(n):
    if d[n] == 0:
        d[n] = fact(n-1)*n

    return d[n]
    

if __name__ == "__main__":
    t = int(input())
    d = [0] * 30
    d[0] = 1
    d[1] = 1
    
    for _ in range(t):
        n, m = map(int, input().split())
        permute = int(fact(m)/(fact(m-n)*fact(n)))
        print(permute)
    