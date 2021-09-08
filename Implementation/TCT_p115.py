#왕실의 나이트
'''체스판과 같은 8*8 좌표 평면중 한 칸에 나이트가 서 있다. 나이트의 위치가 주어졌을 때 나이트가 이동할 수 있는 경우의 수를 출력하는 프로그램을 작성하시오. 행 위치를 표현할 때는 1부터 8로 표현하며, 열은 a부터 h로 표현한다. 입력은 a1과 같이 된다.'''

input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1

moves = [(-1,2), (-1,-2), (1,2), (1,-2), (2,1), (2,-1), (-2,1), (-2,-1)]
cnt = 0

for move in moves:
    if row+move[0] >= 1 and row+move[0] <= 8 and column+move[1] >= 1 and column+move[1] <= 8:
        cnt+=1

print(cnt)
        