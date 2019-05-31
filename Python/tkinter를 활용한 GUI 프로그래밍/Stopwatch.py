from tkinter import *

top = Tk()
top.title("스톱 워치")

cnt = 0
def StopWatch():
    if running:
        global cnt
        cnt += 1
        lbl.config(text=str(cnt))
    top.after(1000, StopWatch)

def start():
    global running
    running = True

def stop():
    global running
    running = False

def reset():
    global cnt
    cnt = 0
    lbl.config(text=str(cnt))

lbl = Label(top, font=("Helvetica", 20), fg="red")
lbl.pack()

running = False
StopWatch()

btn1 = Button(top, text='Start', width=25, command=start).pack()
btn2 = Button(top, text='Stop', width=25, command=stop).pack()
btn3 = Button(top, text='Reset', width=25, command=reset).pack()

top.mainloop()
