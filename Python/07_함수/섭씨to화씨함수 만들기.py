def CtoF(C):
    F = 9/5*C+32
    return F

deg = eval(input('섭씨 온도: '))
print('화씨 온도:', CtoF(deg))
