n = int(input())
cnt = 0

while True:
    if n%5 ==0:
        n = n-5
        cnt+=1
    else:
        n = n-3
        cnt+=1
    if n<=0:
        break;
    
if n<0:
    print(-1)
else:
    print(cnt)
    
#입력된 값이 5의 배수이면 5를 빼주고, 아니라면 3을 뺀 후 다시 5의 배수인지 확인하는 작업을 반복한다.
#빼기를 반복하다 n값이 음수가 되면 5, 3만으로 만들 수 없는 값이므로 -1을 출력한다.
