#로마 숫자

dic = {'I':(1,0), 'V':(5,1), 'X':(10,2), 'L':(50,3), 'C':(100,4), 'D':(500,5), 'M':(1000,6)}
dic2 = {i:j for i,j in zip(range(0,7),dic.keys())}

def RtoA(roma):
    result = 0
    init = -1
    roma = roma[::-1]
    for i in roma:
        if init <= dic[i][1]:
            result += dic[i][0]
            init = dic[i][1]

        else:
            result -= dic[i][0]

    return result

def AtoR(num):
    result = ''
    pre_div = 0
    for i in range(6,-1,-1):
        m = 10**(i//2) if i&1==0 else 5*10**(i//2)
        
        divnum = num//m
        
        if divnum == 4:
            if pre_div == 1:
                result = result[:-1]
                result += dic2[i]+dic2[i+2]
            else:
                result += dic2[i]+dic2[i+1]
        else:
            result += dic2[i]*divnum

        num -= divnum*m
        pre_div = divnum
    return result

n = input()
m = input()
result = RtoA(n) + RtoA(m)
print(result)
print(AtoR(result))