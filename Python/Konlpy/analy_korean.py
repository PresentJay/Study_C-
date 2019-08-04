from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
import tkinter.scrolledtext as tkst
import tkinter.ttk
from konlpy.tag import Kkma
#from openpyxl import *

root = Tk()
root.title("품사태깅 _PresentJay")
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
        messagebox.showinfo('경고','Start index를 기입해주세요!')
    elif (EndNum.get()==''):
        messagebox.showinfo('경고','End index를 기입해주세요!')
    elif (SheetName.get()==''):
        messagebox.showinfo('경고','분석할 시트명을 기입해주세요!')
    else:
        messagebox.showinfo("Alert", StartNum.get()+'번에서 '+ EndNum.get()+'번까지의 품사태깅을 시작합니다.')
        File_selection()
        

def Indivisual_Analysis():
    if (analysis.get('1.0', 'end-1c')==''):
        messagebox.showinfo('경고','개별 분석할 문장을 기입해주세요!')
    else:
        messagebox.askokcancel("Alert", "분석을 진행할까요?")
        messagebox.showinfo("Alert", '품사태깅 시작')
        tmpstr = kkma.pos(analysis.get('1.0', 'end-1c'))
        resultbox.delete('1.0', END)
        for i in range(0, len(tmpstr), 1):
            tmpstr[i]='/'.join(tmpstr[i])
        tmpstr = ' + '.join(tmpstr)
        print(type(tmpstr))
        resultbox.insert('1.0', tmpstr)
        messagebox.showinfo('Finish!', '완료되었습니다!')
    

info_ = Label(root, text='엑셀 분석하기', relief='solid').grid(row=0, columnspan=2)
root.grid_rowconfigure(1, minsize=20)

StartNum_ = Label(root, text="Start Index=>").grid(row=2, column=0)
StartNum = Entry(root)
StartNum.grid(row=2, column=1)
EndNum_ = Label(root, text="End Index=>").grid(row=3, column=0)
EndNum = Entry(root)
EndNum.grid(row=3, column=1)
SheetName_ = Label(root, text="분석할 시트명=>").grid(row=4,column=0)
SheetName = Entry(root)
SheetName.grid(row=4, column=1)
SheetName.insert(0, 'Sheet1')

do_btn = Button(root, text='  Do!  ', command=main_)
do_btn.grid(row=5, columnspan=2, sticky=W+E)

root.grid_rowconfigure(6, minsize=60)
s=tkinter.ttk.Separator(root, orient="horizontal")	
s.grid(row=7,columnspan=2, sticky=W+E+N+S)
root.grid_rowconfigure(8, minsize=50)
info1 = Label(root, text='직접 분석하기', relief='solid').grid(row=8, columnspan=2)

analysis_ = Label(root, text="개별 분석할 문장").grid(row=9, columnspan=2, stick=W+E)
root.grid_rowconfigure(10, minsize=80)
analysis = tkst.ScrolledText(root, width=30, height=3)
analysis.grid(row=10, columnspan=2, sticky=W+E+N+S)
analysis.focus_set() 

indiv_do_btn = Button(root, text='분석', command=Indivisual_Analysis)
indiv_do_btn.grid(row=11, columnspan=2, sticky=W+E)

resultbox = tkst.ScrolledText(root, width=30, height=3)
root.grid_rowconfigure(12, minsize=80)
resultbox.grid(rows=12, columnspan=2, sticky=W+E+N+S)

root.mainloop()
