def sum(begin, end):
    result = 0
    for i in range(begin, end+1):
        result += i
    return result

print('함수 호출 전')
print('1~10까지의 합:',sum(1,10))
print('5~35까지의 합:',sum(5,35))
