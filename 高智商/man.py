import math
count = input("lol")
data = ""
for i in range(int(count)):
    dataa = input("enter data")

    data += dataa + " "


data = data.split(" ")
print(data)


nc = 0
list = []
for i in range(int(count)):
    tag = data[nc]
    pat1 = math.ceil(((float(data[nc+1]) + float(data[nc+2]))*0.6))
    pat2 = math.ceil(((float(data[nc+3]) + float(data[nc+4]))*0.4))
    all = pat1 + pat2
    et = (tag, all)
    list.append(et)
    nc = nc + 5

list = sorted(list, key=lambda s: s[1], reverse=True)

world = ""
for i in range(3):

    world += str(list[i][0])+","


print(world)
