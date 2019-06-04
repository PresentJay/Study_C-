from tkinter import *

top = Tk()
lab = ""

def ft():
    global lab
    if len(lab)==0: lab="클릭했습니다."
    else: lab+="\n클릭했습니다."
    lb["text"] = lab

lb = Label(top)
lb.pack()

bt = Button(top, text="클릭하세요!", command=ft)
bt.pack()

top.mainloop()
