from tkinter import *

win = Tk()
win.title("체크 버튼")

def varState():
    print('var1:', v1.get())
    print('var2:', v2.get())
    print('var3:', v3.get())

lb = Label(win, text="선호하는 프로그래밍 언어 모두 선택:").pack(padx=10)

v1 = IntVar()
v2 = IntVar()
v3 = IntVar()

cb1 = Checkbutton(win, text="Python", variable=v1)
cb2 = Checkbutton(win, text="Java", variable=v2)
cb3 = Checkbutton(win, text="C++", variable=v3)
cb1.pack(padx=10, anchor='w')
cb2.pack(padx=10, anchor='w')
cb3.pack(padx=10, anchor='w')


bt = Button(win, text="show", command=varState)
bt.pack()

win.mainloop()
