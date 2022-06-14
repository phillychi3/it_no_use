import re

num = ["A","B", "C", "D", "E", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V", "X", "Y", "W", "Z", "I", "O"]

def main(data):
    if re.match(r"^[A-Z]{1}[1-2]{1}[0-9]{8}$",data):
        data = list(data)
        ct = 0
        for i in num:
            ct+=1
            if i == data[0]:
                break
        ct=ct+9
        fn = ct%10*9+int(ct/10)
        for i,o in enumerate(data[1:9]):
            fn+=int(o)*(8-i)
        fn+=int(data[9])
        if fn%10 == 0:
            print("yes")
        else:
            print("no")

if __name__ == '__main__':
    data = input("請輸入身分證: ")
    main(data)



