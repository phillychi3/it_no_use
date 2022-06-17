def addlist(list1,list2):
    list3 = []
    for i in range(len(list1)):
        list3.append(int(list1[i])+int(list2[i]))
    return list3
list1 = []
list2 = []
for i in range(3):
    list1 = list1 + input("pls input list1 ").split()
for i in range(3):
    list2  = list2 + input("pls input list2 ").split()
list3 = addlist(list1,list2)
for i in range(3):
    for j in range(3):
        print(list3[i+j],end=" ")
    print("\n")



