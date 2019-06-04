from tkinter import *
top = Tk()

def ft():
    print("클릭했습니다.")

bt = Button(top, text="클릭하세요!", command=ft).pack()

top.mainloop()

