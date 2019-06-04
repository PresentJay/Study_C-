from tkinter import *
import random

w=Tk()
w.title("가위 바위 보 게임")

def selection(var):
    img = [PhotoImage(file='image/scissor.png'), PhotoImage(file='image/rock.png'), PhotoImage(file='image/paper.png')]
    user_lb = Label(w, text='사용자', compound='top', image=img[var])
    user_lb.image = img[var]
    user_lb.grid(row=0,column=0)
    com_img = random.randrange(0,3)
    com_lb = Label(w, text='컴퓨터', compound='top', image=img[com_img])
    com_lb.image = img[com_img]
    com_lb.grid(row=0,column=2)
    
    if var==com_img:
        arrow_lb = Label(w, text='=====', font='Helvetica 30')
        result_lb = Label(w, text='비김!', font='Helvetica 15', fg='black', width=15)
    elif (var==0 and com_img==1) or (var==1 and com_img==2) or (var==2 and com_img==0):
        arrow_lb = Label(w, text='<<<<<', font='Helvetica 30')
        result_lb = Label(w, text='컴퓨터 승!', font='Helvetica 15', fg='red', width=15)
    else:
        arrow_lb = Label(w, text='>>>>>', font='Helvetica 30')
        result_lb = Label(w, text='사용자 승!', font='Helvetica 15', fg='blue', width=15)
    arrow_lb.grid(row=0, column=1)
    result_lb.grid(row=1,column=1)

btn_scissor = Button(w, text="가위", bg='yellow', width=15, command=lambda:selection(0))
btn_rock = Button(w, text="바위", bg='yellow', width=15, command=lambda:selection(1))
btn_paper = Button(w, text="보", bg='yellow', width=15, command=lambda:selection(2))

btn_scissor.grid(row=2, column=0)
btn_rock.grid(row=2, column=1, padx=80)
btn_paper.grid(row=2, column=2)

w.mainloop()
