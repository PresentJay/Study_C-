from tkinter import *

w = Tk()

Button(w, text='아래쪽', width=10).pack(side=BOTTOM)
Button(w, text='위쪽', width=10).pack(side=TOP)

Button(w, text='왼쪽', width=10).pack(side=LEFT, pady=1)
Button(w, text='오른쪽', width=10).pack(side=LEFT, padx=1, pady=1)

w.mainloop()

