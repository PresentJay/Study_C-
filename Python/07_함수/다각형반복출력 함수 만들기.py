import turtle
t=turtle.Turtle()
t.speed(50)
def poly(n, leng):
    for i in range(n):
        t.forward(leng)
        t.left(360//n)

for i in range(10):
    poly(5, 100)
    t.left(360//10)
    
    
