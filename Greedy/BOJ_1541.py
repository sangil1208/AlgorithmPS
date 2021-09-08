'''풀기 전 아이디어: -가 나오기 전까지 값들은 더한다 -가 나오면 괄호 시작 다음 - 가 나오면 괄호 닫음
이 방식으로 최대한 많은 -를 만드는 것 --> 03과 같은 숫자도 입력되므로 eval불가능. 따라서 -를 기준으로 나눠준후 계산 
-이후 +가 나오는 부분은 전부 -로 계산'''

a = input()
a = a.split('-')
temp = []
result = 0


for i in range(len(a)):
    temp = a[i].split('+')
    if i == 0:
        for j in temp:
            result += int(j)
    else:
        for j in temp:
            result -= int(j)

print(result)

