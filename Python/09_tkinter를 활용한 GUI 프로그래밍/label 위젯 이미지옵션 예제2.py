from tkinter import *
top = Tk()

paper = PhotoImage(file="image/paper.png")
lb = Label(top, padx=10, compound=CENTER, text="Paper Image", image=paper).pack(side='right')

top.mainloop()
