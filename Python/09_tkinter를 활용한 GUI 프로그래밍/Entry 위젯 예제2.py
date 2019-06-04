from tkinter import *
top = Tk()

def showName():
    print("User Name:", en.get())

lb = Label(top, text="User Name").grid(row=0)
en = Entry(top)
en.grid(row=0, column=1)

bt1 = Button(top, text='Show', command=showName)
bt1.grid(row=1, column=0)
bt2 = Button(top, text="Quit", command=top.quit)
bt2.grid(row=1, column=1)

top.mainloop()
