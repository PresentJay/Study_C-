#집합의 비교연산자는 부분집합을 검사할 때 사용
st6 = {1,2,3,4,5,6}
st7 = {1,3,5}
print(st6>st7)

#집합연산
sa = {1,3,5}
sb = {1,2,4}
print(sa&sb)

print(sa.union(sb))
print(sa-sb)