def prt(n, a, b):   #프린팅 함수
    print("*\t*\t*")
    for i in range(n):
        for j in range(n):
            if a[i][j]==0:
                print("         ",end="")
                continue
            if j!=0: print("+",str(a[i][j])+"x^"+str(j+1), end=" ")
            else: print(str(a[i][j])+"x^"+str(j+1), end=" ")
        print(" =",b[i])
    print("*\t*\t*\n")

n = int(input("연립방정식 수 : "))
x = [0.0]*n
a = [[float(x) for x in input("방정식 입력 >> ").split()] for y in range(n)]
b = [float(x) for x in input("우항 입력 >> ").split()]
print("\n입력한 연립방정식\n")
prt(n,a,b)

#s값 설정 (축척화를 위한 각 행의 가장 큰 계수값 벡터)
s=[0]*n
for i in range(0,n,1):
    s[i] = abs(a[i][1])
    for j in range(1,n,1):
        if abs(a[i][j])>s[i]: s[i] = abs(a[i][j])
# 

for k in range(0,n-1,1):
    #Pivot화
    p=k
    big=abs(a[k][k]/s[k])
    for ii in range(k+1,n,1):
        dummy = abs(a[ii][k]/s[ii]) #축척화로 피봇팅 판단
        if dummy>big:
            big = dummy
            p=ii
    if p!=k:
        for jj in range(k,n,1): a[p][jj], a[k][jj] = a[k][jj], a[p][jj]
        b[p], b[k] = b[k], b[p]
        s[p], s[k] = s[k], s[p]     #각 행의 가장 큰 계수값 변경
        print("<< 피봇팅 발생! :",p+1,"행 <->",k+1,"행 >>\n")
        prt(n,a,b)
    #

    #소거단계
    for i in range(k+1,n,1):
        factor = a[i][k]/a[k][k]
        for j in range(k,n,1):
            a[i][j] = round(a[i][j] - factor * a[k][j],6)
        b[i] = round(b[i] - factor*b[k],6)
    print(k+1,"차 소거 결과")
    prt(n,a,b)
    #

#대입단계
x[n-1]= round(b[n-1]/a[n-1][n-1],6)
print("x^"+str(n)+"=",x[n-1])
for i in range(n-2,-1,-1):
    sum = 0
    for j in range(i+1,n,1):
        sum += a[i][j] * x[j]
        x[i] = round((b[i]-sum) / a[i][i],6)
    print("x^"+str(i+1)+"=",x[i])
else: print("\n*\t*\t*\n")
#