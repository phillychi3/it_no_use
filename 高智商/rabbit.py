
# 費撥那契數列
data = input("请输入一个数字")
data = int(data)
rabbit = []

for i in range(data):
    if i == 0:
        rabbit.append(1)
    elif i == 1:
        rabbit.append(1)
    else:
        rabbit.append(rabbit[i-1] + rabbit[i-2])

print(rabbit[len(rabbit)-1])

    



