from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
from konlpy.tag import Kkma
#from openpyxl import *

root = Tk()
root.title("품사태깅 _PresentJay")
root.geometry("680x480+100+100")
root.resizable(False, False)

kkma = Kkma()


def File_selection():
    root.filename =  filedialog.askopenfilename(initialdir = "/",title = "choose your Excel file",filetypes = (("Excel files","*.xlsx"),("all files","*.*")))
    load_wb = load_workbook(root.filename, data_only=True)
    load_ws = load_sheet

def analysis(source, dst):
    dstlen= len(dst.get())-1
    dst.delete(0, dstlen)
    dst.insert(0, kkma.pos(source))
    
    
def main_():
    if (StartNum.get()==''):
        messagebox.showinfo('Start index를 기입해주세요!')
    elif (EndNum.get()==''):
        messagebox.showinfo('End index를 기입해주세요!')
    elif (SheetName.get()==''):
        messagebox.showinfo('분석할 시트명을 기입해주세요!')
    else:
        messagebox.showinfo("Alert", StartNum.get()+'번에서 '+ EndNum.get()+'번까지의 품사태깅을 시작합니다.')
        File_selection()
        

#def Indivisual_Analysis():
    



StartNum_ = Label(root, text="Start Index=>").grid(row=0, column=0)
StartNum = Entry(root)
StartNum.grid(row=0, column=1)
EndNum_ = Label(root, text="End Index=>").grid(row=0, column=2)
EndNum = Entry(root)
EndNum.grid(row=0, column=3)
SheetName_ = Label(root, text="분석할 시트명=>").grid(row=0,column=4)
SheetName = Entry(root)
SheetName.grid(row=0, column=5)
SheetName.insert(0, 'Sheet1')

do_btn = Button(root, text='  Do!  ', command=main_)
do_btn.grid(row=1, column=2)

analysis_ = Label(root, text="개별 분석할 문장=>").grid(row=2, column=0)
analysis = Entry(root)
analysis.grid(row=2, column=1, columnspan=4)

indiv_do_btn = Button(root, text='분석', command=Indivisual_Analysis)
indiv_do_btn.grid(row=2, column=5)

resultbox = Entry(root)
resultbox.grid(row=3, column=0)
resultbox.state = readonly

root.mainloop()
