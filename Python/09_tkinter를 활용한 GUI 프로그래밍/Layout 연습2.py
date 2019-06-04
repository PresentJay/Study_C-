from tkinter import *

w = Tk()

weekday=['Mon','Tue','Wed','Thu','Fri','Sat','Sun']
day=-1

for r in range(6):
    for c in range(7):
        if r==0:
            lbl = Label(w, text=weekday[c], width=5)
            lbl.grid(row=r, column=c)
        else:
            if day>0 and day<31:
                lbl = Label(w, text=str(day), width=5)
                lbl.grid(row=r, column=c)
            day+=1
            
