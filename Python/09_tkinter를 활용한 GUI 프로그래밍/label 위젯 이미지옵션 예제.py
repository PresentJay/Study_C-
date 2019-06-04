from tkinter import *
top = Tk()

rock = PhotoImage(file="image/rock.png")
lb1 = Label(top, image=rock).pack(side='left')
lb2 = Label(top, padx=10, text="Rock Image").pack(side='right')

top.mainloop()