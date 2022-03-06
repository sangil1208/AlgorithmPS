##그룹 단어 체커

n = int(input())
words = []
for i in range(n):
    words.append(input())

cnt = 0


for word in words:
    flag = 0
    for i in range(len(word)-1):
        if word[i] != word[i+1]:
            temp = word[i]
            for j in range(i+2, len(word)):
                if word[j] == temp:
                    flag = 1
                    break
    if flag == 0:
        cnt += 1

'''문자와 그 다음 문자가 다르면 해당 문자를 저장해 놓은뒤, 문자열에서 해당 문자 다음 문자들과 저장한 문자를 비교해서 같은 것이
나오지 않는 경우에만 cnt를 증가시킨다.'''

print(cnt)

