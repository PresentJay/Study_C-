import turtle
t=turtle.Turtle()
t.speed(50)

def square(length):
    for i in range(4):
        t.forward(length)
        t.left(90)

leng = 50
for n in range(3):
    square(leng)
    leng+=30
