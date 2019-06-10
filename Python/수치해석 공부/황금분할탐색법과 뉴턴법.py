#특정 함수의 최대값을 구하는 방법
#수치해석(19년도 1학기, 1분반) 4번째 과제
#20143174 정현재
f = lambda x: 4*x-(1.8)*pow(x,2)+(1.2)*pow(x,3)-(0.3)*pow(x,4)
fp = lambda x:4-(3.6)*x+(3.6)*pow(x,2)-(1.2)*pow(x,3)
fpp = lambda x:(-3.6)+(7.2)*x-(3.6)*pow(x,2)
R = (pow(5,(0.5))-1)/2  #황금비

def gold(xlow, xhigh, maxit, es):
    print('- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -')
    print('iter\txl\tf(xl)\tx2\tf2\tx1\tf1\txu\tf(xu)\td\tea')
    xl, xu, iter = xlow, xhigh, 1
    d = R * (xu - xl)
    x1, x2 = xl+d, xu-d
    f1, f2 = f(x1), f(x2) 
    if f1 > f2: xopt, fx = xl, f1
    else: xopt, fx = x2, f2
    print(str(iter)+'\t'+str(round(xl,4))+'\t'+str(round(f(xl),4))+'\t'+str(round(x2,4))+
            '\t'+str(round(f2,4))+'\t'+str(round(x1,4))+'\t'+str(round(f1,4))+'\t'+str(round(xu,4))+
            '\t'+str(round(f(xu),4))+'\t'+str(round(d,4))+'\t0')
    while(True): 
        d *= R
        if f1 > f2:
            xl, x2 = x2, x1
            x1, f2 = xl+d, f1
            f1 = f(x1)
        else:
            xu, x1 = x1, x2
            x2, f1 = xu-d, f2
            f2 = f(x2)
        iter+=1
        if f1 > f2:
            xopt, fx = x1, f1
        else:
            xopt, fx = x2, f2
        if xopt!=0: ea = (1-R)*abs((xu-xl)/xopt)*100
        print(str(iter)+'\t'+str(round(xl,4))+'\t'+str(round(f(xl),4))+'\t'+str(round(x2,4))+
            '\t'+str(round(f2,4))+'\t'+str(round(x1,4))+'\t'+str(round(f1,4))+'\t'+str(round(xu,4))+
            '\t'+str(round(f(xu),4))+'\t'+str(round(d,4))+'\t'+str(round(ea,4)))    
        if ea<=es or iter>=maxit: break
    print('- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -')
    print('*최대값 x :',round(xopt,4),', *최대값 f(x) :',round(fx,4))

def Newton(x0, es, maxif):
    print('- - - - - - - - - - - - - - - - - - - - - - - - -')
    print('iter\tx\tf(x)\tf\'(x)\tf\'\'(x)\tea')
    xold = x0
    iter = 0
    while(True):
        xi = xold-fp(xold)/fpp(xold)
        iter+=1
        if xi!=0: ea = abs((xi-xold)/xi)*100
        print(str(iter)+'\t'+str(round(xold,4))+'\t'+str(round(f(xold),4))+'\t'+str(round(fp(xold),4))+'\t'+str(round(fpp(xold),4))
            +'\t'+str(round(ea,4)))
        if ea<=es or iter>=maxif: break
        xold = xi
    print('- - - - - - - - - - - - - - - - - - - - - - - - -')
    print('*최대값 x :',round(xi,4),', *최대값 f(x) :',round(f(xi),4))

print("다음 함수의 최대값을 아래의 방법을 이용하여 구하라")
print("f(x)= 4x - 1.8x^2 + 1.2x^3 - 0.3x^4")
print('')
print("(a) 황금분할탐색법(xl=-2, xu-4, es=1%)")
gold(-2,4,100,1)
print('')
print("(c) Newton 법(x0=3, es=1%)")
Newton(3,1,100)