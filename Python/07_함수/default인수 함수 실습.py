#default 인수
#기본값은 마지막에 와야한당

def getSum(end, begin=1):
    result = 0
    for i in range(begin, end+1): result += i
    return result

print('15 까지의 합:', getSum(15))
print('3~25 까지의 합:', getSum(25, 3))
    
