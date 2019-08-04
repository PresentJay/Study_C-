from tkinter import *
from tkinter import filedialog
root = Tk()
root.filename =  filedialog.askopenfilename(initialdir = "/",title = "choose your Excel file",filetypes = (("Excel files","*.xlsx"),("all files","*.*")))
print (root.filename)
root.mainloop()
