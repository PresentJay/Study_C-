#주어진 영단어에서 서로 다른 문자, 각 문자의 갯수 체크하기

c = input("문자열 입력: ")
st = set(c)
for k in st:
    i = 0
    for n in c:
        if k==n: i+=1
    print(k, ':', i, "회")