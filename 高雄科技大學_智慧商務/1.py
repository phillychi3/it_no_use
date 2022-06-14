def num_divide(arg):
    for i in range(2 , arg):
        if arg%i == 0:
            return True
    return False

if num_divide(input("請輸入一個數字: ")):
    print("no")
else:
    print("yes")