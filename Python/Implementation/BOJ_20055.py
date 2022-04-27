n, k = map(int, input().split())

tolerance = list(map(int, input().split()))
robot = [0 for _ in range(2*n)]

res = 0


while True:
    
    end_flag = 0
    temp = tolerance.pop()
    tolerance.insert(0, temp)
    temp = robot.pop()
    robot.insert(0, temp)
    
    if robot[n-1] == 1:
        robot[n-1] = 0
   
    for r in range(len(robot)-1, -1, -1):
        
        if robot[r] == 1:
            if r == len(robot)-1:
                if robot[0] == 0 and tolerance[0] > 0:
                    robot[r] = 0
                    robot[0] = 1
                    tolerance[0] -= 1
            
            else:
                if robot[r] == 1 and robot[r+1] == 0 and tolerance[r+1] > 0:
                    tolerance[r+1] -= 1
                    robot[r+1] = 1
                    robot[r] = 0
                    
    if robot[n-1] == 1:
        robot[n-1] = 0

    if tolerance[0] > 0 and robot[0] == 0:
        tolerance[0] -= 1 
        robot[0] = 1
                      
    res += 1
    for i in tolerance:
        if i == 0:
            end_flag += 1
    
    if end_flag >= k:
        break

print(res)