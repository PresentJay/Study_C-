from tkinter import *

top = Tk()
top.title("가위 바위 보 게임")

def rsp(i):    
    if i == 1:
        lb1 = Label(top, image = scis)
        print("이미지에 가위가 들어갑니다")
    elif i == 2:
        lb1 = Label(top, image = rock)
        print("이미지에 바위가 들어갑니다")
    elif i == 3:
        lb1 = Label(top, image = paper)
        print("이미지에 보가 들어갑니다")
    else:
        lb1 = label(top)
    
    lb1.grid(row=0, column = 0)

    return

scis = PhotoImage(file="scis.png")
rock = PhotoImage(file="rock.png")
paper = PhotoImage(file="paper.png")

lb1 = Label(top, width = 30, height = 30)
lb2 = Label(top, width = 30, height = 30)
lb3 = Label(top, width = 30, height = 30)
lb4 = Label(top, width = 50, height = 10, text = "누가 이길까요?") 

lb1.grid(row=0 ,column = 0)
lb2.grid(row=0,column = 1)
lb3.grid(row=0,column = 2)
lb4.grid(row=1,column = 0,columnspan = 2)

bt1 =Button(top,width = 10,text = "가위",bg="Yellow",command = rsp(1))
bt2 =Button(top,width = 10,text = "바위",bg="Yellow",command = rsp(2))
bt3 =Button(top,width = 10,text = "보",bg="Yellow", command = rsp(3))

bt1.grid(row=2,column = 0)
bt2.grid(row=2,column = 1)
bt3.grid(row=2,column = 2)

top.mainloop()
