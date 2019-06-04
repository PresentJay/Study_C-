from tkinter import *

w = Tk()
w.title("BMI 계산")

def calc():
    height = float(en1.get())
    weight = float(en2.get())
    bmi = weight / height **2
    en1.delete(0,END)
    en2.delete(0,END)
    en3.insert(0,bmi)

lb1 = Label(w, text="키(m)")
lb2 = Label(w, text="BMI")
lb3 = Label(w, text="몸무게(kg)")
lb1.grid(row=0,column=0)
lb2.grid(row=0,column=2)
lb3.grid(row=1,column=0)

en1 = Entry(w)
en2 = Entry(w)
en3 = Entry(w)
en1.grid(row=0, column=1)
en2.grid(row=1, column=1)
en3.grid(row=1, column=2)

bt1 = Button(w, width=10, text="계 산", command=calc)
bt1.grid(row=2, column=2)

w.mainloop()
