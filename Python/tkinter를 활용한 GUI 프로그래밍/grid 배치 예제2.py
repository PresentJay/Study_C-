from tkinter import *

w = Tk()

bt0 = Button(w, text='r0', width=20)
Button(w, text='r1, c0', width=10).grid(row=1, column=0)
Button(w, text='r2, c0', width=10).grid(row=2, column=0)
Button(w, text='r1, c1', width=10).grid(row=1, column=1)
Button(w, text='r2, c1', width=10).grid(row=2, column=1)
bt0.grid(row=0, column=0, columnspan=2)

w.mainloop()
