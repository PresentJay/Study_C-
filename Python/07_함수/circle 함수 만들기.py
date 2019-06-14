import turtle
t=turtle.Turtle()
t.shape('turtle')
t.speed(50)
def cCircle(r):
    t.penup()
    t.right(90)
    t.forward(r)
    t.left(90)
    t.pendown()
    t.circle(r)
    t.penup()
    t.left(90)
    t.forward(r)
    t.right(90)
    t.pendown()

n=30
for i in range(3):
    cCircle(n)
    n+=30
