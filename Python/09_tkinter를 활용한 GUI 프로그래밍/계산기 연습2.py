from tkinter import *

w = Tk()
w.title("Calculator")

board = [['7','8','9','/','C'],
         ['4','5','6','*','('],
         ['1','2','3','-',')'],
         ['0','.','=','+',' ']]

lb1 = Label(w,bg="yellow")
lb1.pack(side=TOP, fill='x')

for r in range(5):
    for c in range(5):
        Bt = Button(w,text=board[r][c], width=5)
        Bt.grid(row=r, column=c)

w.mainloop()
