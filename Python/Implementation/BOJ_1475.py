'''
각 숫자가 몇번 나왔는지를 저장하는 별도의 리스트를 생성.
6이나 9가 나온 경우는 모두 6의 개수를 증가시킴
그후, 6에 저장된 수가 짝수면 2로 나눈 값으로 변경
6에 저장된 수가 홀수라면 2로 나누고 +1 (나머지에 대해 추가로 한세트 필요)
이렇게 저장된 counting 리스트에서 최댓값이 정답
'''

d = [0] * 10

num = str(input())

for n in num:
    if int(n) == 9 or int(n) == 6:
        d[6] += 1
    else:
        d[int(n)] += 1

if d[6]%2 == 0:
    d[6] = d[6]//2
else:
    d[6] = d[6]//2 + 1

print(max(d))