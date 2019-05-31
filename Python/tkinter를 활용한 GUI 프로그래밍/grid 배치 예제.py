from tkinter import *

w = Tk()

Button(w, text='r0, c0', width=10).grid(row=0, column=0)
Button(w, text='r1, c0', width=10).grid(row=1, column=0)
Button(w, text='r2, c0', width=10).grid(row=2, column=0)
Button(w, text='r0, c1', width=10).grid(row=0, column=1)
Button(w, text='r1, c1', width=10).grid(row=1, column=1)
Button(w, text='r2, c1', width=10).grid(row=2, column=1)

w.mainloop()
