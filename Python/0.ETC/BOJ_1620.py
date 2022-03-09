'''
n, m 이 10만개가 최대이므로, 순차 탐색 시 백억번의 연산이 최대로 필요해 2초 = 약4000만회 를 초과한다.
해시를 이용해 O(1)시간에 탐색 수행하도록 구현한다. 파이썬에서 해시는 딕셔너리 자료형으로 구현 가능하다.
key로 value 검색이 가능하고, value로 key 검색을 위해서는 dict를 뒤집어 reverse_dict를 만든 후 검색을 수행한다.
'''

import sys
input = sys.stdin.readline

if __name__ == "__main__":
    n, m = map(int, input().split())
    
    org_dict = {}
    
    for i in range(1, n+1):
        org_dict[input().rstrip()] = i
        
    reverse_dict = dict(map(reversed,org_dict.items()))
        
    for _ in range(m):
        ques = input().rstrip()
        if ques.isdigit() == True:
            print(reverse_dict[int(ques)])
        else:
            print(org_dict[ques])
