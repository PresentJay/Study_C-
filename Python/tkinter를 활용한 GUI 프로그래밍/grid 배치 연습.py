from tkinter import *

w = Tk()

Button(w, text='아래쪽', side=BOTTOM)
Button(w, text='위쪽')
Button(w, text='왼쪽', side=LEFT)
Button(w, text='오른쪽', side=LEFT)

w.mainloop()
