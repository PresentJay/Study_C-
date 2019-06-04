from tkinter import *
window = Tk()

lb = Label(window)
lb['text']= "hello GUI world!"
lb['width']= 20
lb['height']= 2
lb['font']= 'helvetica 14 italic'
lb['relief']= RAISED

lb.pack()

window.mainloop()