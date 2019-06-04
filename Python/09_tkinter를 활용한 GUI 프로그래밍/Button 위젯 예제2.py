from tkinter import *
top = Tk()

click = PhotoImage(file='image/scissor.png')
bt = Button(top, image=click, text="클릭하세요!", compound=LEFT).pack()

top.mainloop()

