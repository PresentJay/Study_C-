def divisor(a,b=0):
    lst = []
    for i in range(1,a+1,1):
        if a%i==0 and b%i==0: lst.append(i)
    return lst

print(divisor(24, 36))
print(divisor(18))
