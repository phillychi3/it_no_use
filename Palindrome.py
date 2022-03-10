import numpy;import math;import os
array1=[];ansarray=[];noansanscount=0;noansans=0;noans=0;x=0
c=input("請輸入東西");
#c="aaaaf" DEBUG
lean=len(c)
for i in range(lean):    
    d=c[i]
    array1=array1+[ord(d)]
count=numpy.bincount(array1) 
for i in range(len(count)):
    if  count[i]!=0 and count[i] % 2 == 0:
        for x in range(int(count[i]/2)):               
            ansarray.insert(0,chr(i))
            ansarray.append(chr(i))
    elif count[i]!=0 and count[i]%2!=0:     
        noans+=1
        if noans>1:            
            break
        else:            
            noansans=i
            noansanscount=count[i]   
    x=0         
if noans>1:
    print("no ans")
else:
    for i in range(noansanscount):
        ansarray.insert(math.ceil(len(ansarray)/2),chr(noansans))
    print(ansarray)  
os.system("pause")




    
