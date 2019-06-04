from tkinter import *

w = Tk()
w.title("라디오 버튼")

ch = IntVar()
wid = 0
hei = 0

def Choice():
    global wid
    global hei
    s = ch.get()
    if s==1: img = PhotoImage(file="image/rock.png")
    elif s==2: img = PhotoImage(file="image/scissor.png")
    elif s==3: img = PhotoImage(file="image/paper.png")

    if img.width() > wid: wid = img.width()
    if img.height() > hei: hei = img.height()
    
    
    lb2 = Label(fr, image = img, width=wid, height=hei, bg='white')
    lb2.image = img
    lb2.grid(row=0, column=1, rowspan=10)
    w.update_idletasks()

Label(w, text='가위, 바위, 보 중 선택하세요').pack()
fr = Frame(w)
fr.pack(side=LEFT)

rb1 = Radiobutton(fr, text="가위", variable=ch, value=2, command=Choice)
rb1.grid(row=0, column=0, sticky='w')
rb2 = Radiobutton(fr, text="바위", variable=ch, value=1, command=Choice)
rb2.grid(row=1, column=0, sticky='w')
rb3 = Radiobutton(fr, text="보", variable=ch, value=3, command=Choice)
rb3.grid(row=2, column=0, sticky='w')
w.mainloop()
