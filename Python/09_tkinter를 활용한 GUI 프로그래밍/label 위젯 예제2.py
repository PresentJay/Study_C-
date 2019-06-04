from tkinter import *
window = Tk()

lb = Label(window, text="Hello GUI world!",
                    width=20, height=2,
                    font='helvetica 14 italic',
                    relief=RAISED)

lb.pack()

window.mainloop()