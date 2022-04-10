data = list(input())

data_1 = data[:int(len(data)/2)]
data_2 = data[int(len(data)/2):]

sum1 = 0
sum2 = 0

for i in range(int(len(data_1))):
    sum1 += int(data_1[i])
    
for i in range(int(len(data_2))):
    sum2 += int(data_2[i])    
    
if sum1 == sum2:
    print("LUCKY")
    
else:
    print("READY")
    