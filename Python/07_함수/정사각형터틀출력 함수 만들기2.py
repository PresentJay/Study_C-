import turtle
t=turtle.Turtle()
t.speed(100)
def sqaure():
    for i in range(4):
        t.forward(50)
        t.left(90)

for i in range(4):
    sqaure()
    t.right(90)

t.penup()
t.forward(200)
t.pendown()

for i in range(4):
    sqaure()
    t.left(90/3)
