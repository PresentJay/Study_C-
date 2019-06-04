def square(len):
    area = len*len
    circum = 4*len
    return (area, circum)

radius = int(input("한 변의 길이: "))
tupVal = square(radius)

print("넓이:",tupVal[0],"둘레:",tupVal[1])
#튜플은 값을 전달할 수 없는 자료구조이다
#튜플에 튜플을 전달해, 새롭게 아예 바꾸는 것은 가능하다