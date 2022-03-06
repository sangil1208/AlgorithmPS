#덩치
n = int(input())
people = []
grade = [1] * n
for _ in range(n):
    x, y = map(int, input().split())
    people.append((x,y))
    
for i in range(n):
    for j in people:
        if people[i][0]<j[0] and people[i][1]<j[1]:
            grade[i]+=1

for i in grade:
    print(i, end=' ')
   

