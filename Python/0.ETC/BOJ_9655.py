'''
규칙을 발견하는 문제. 돌이 홀수개인데 1개 혹은 3개씩 가져가다보면 A가 항상 마지막에 가져간다.
반면 돌이 짝수개인데 1개 혹은 3개씩 가져가다보면 B가 항상 마지막에 가져간다.
'''

import sys
input = sys.stdin.readline

n = int(input())

if n%2 != 0:
    print("SK")
else:
    print("CY")