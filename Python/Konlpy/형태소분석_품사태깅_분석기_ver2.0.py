from tkinter import *
from tkinter import messagebox, filedialog
import tkinter.scrolledtext as tkst
import tkinter.ttk
from konlpy.tag import Kkma

#from openpyxl import *

#tkinter 기본설정
root = Tk()
root.title("품사태깅")
root.resizable(False, False)

#konlpy - Kkma tag 사용
kkma = Kkma()

#엑셀파일 선택 (선택여부에 따라 다른 Event를 위해, Boolean return : 중간에 취소하면 False) 
def File_selection():
    root.filename= ""
    root.filename =  filedialog.askopenfilename(initialdir = "/",title = "choose your Excel file",filetypes = (("Excel files","*.xlsx"),("all files","*.*")))
    if root.filename != "": return True
    else: return False

#분석 루틴 (Kkma tag 분석 후, 원하는 형식으로 변형하는 Alogorithm
def Analysis_(src):
    tmpstr = kkma.pos(src) # 매개변수로 주어진 문자열을 선분석
    for i in range(0, len(tmpstr), 1): #분석된 데이터열을 전체 검사하는 루틴 (튜플의 리스트로 구현되어 있음. 데이터열은 튜플을 검사하는 수준)
        tmpstr[i]='/'.join(tmpstr[i])  #각 튜플을 "/"으로 병합 (ex : {내: NP} (튜플형) -> '내/NP' (문자열))
    tmpstr = ' + '.join(tmpstr) # 위 루틴으로 tmpstr이 튜플의 리스트에서, 문자열의 리스트로 되면, join으로 각 개체들을 묶음 (ex : ["내/NP", "이름/NNG"] (리스트) -> "내/NP + 이름/NNG" (문자열))
    return tmpstr #최종적으로 완성된 문자열을 리턴


#주 동작 루틴 (Do버튼) : 엑셀 루틴
def main_():
    # 필수 데이터 유효성검사
    if (StartNum.get()==''):
        messagebox.showinfo('경고','Start index를 기입해주세요!')
    elif (EndNum.get()==''):
        messagebox.showinfo('경고','End index를 기입해주세요!')
    elif (SheetName.get()==''):
        messagebox.showinfo('경고','분석할 시트명을 기입해주세요!')
    elif (ColumnCall.get()==''):
        messagebox.showinfo('경고','분석할 열의 영어알파벳을 기입해주세요!')
    elif (ColumnReturn.get()==''):
        messagebox.showinfo('경고','결과값의 열 영어알파벳을 기입해주세요!')
    # 모두 통과시
    else:
        sn = int(StartNum.get()) #시작 번호 기억  => 검사 당시의 동작 목표 순번이 될 것 (dynamic)
        en = int(EndNum.get())   #끝 번호 기억    => 검사 당시의 종료 목표 순번이 될 것 (static)
        
        if File_selection(): #File_selection을 실행해서 True가 리턴된경우 진행(정상 선택시)
            messagebox.showinfo("Alert", str(sn)+'번에서 '+str(en)+'번까지의 품사태깅을 시작합니다.')

            #선택한 엑셀파일 데이터 로드
            load_wb = load_workbook(root.filename, data_only=True)
            load_ws = load_wb[SheetName.get()]
            toggle = False  #검사 후 2회 continue(건너뜀)을 위한 boolean
            go_on = False   #시작값(StartNum) 검사 전, 끝값(EndNum) 검사 후 데이터 분석 제한을 위한 boolean
            cnt = 0         #분석할 열 전체를 불러와 순번태그를 검색하지만, 행번호를 저장할 수 없으므로 만드는 counting integer
            for i in load_ws[ColumnCall.get()]: #분석할 열 전체 데이터 call (인식된 cell까지만)
                cnt+=1 #count 증가 (시작값은 1이므로)
                if (i.value == en+1):  #종료 조건문이 선행되어야 함. 순서대로 조건을 읽을 때, go_on 조건만 먼저 확인할 경우 버그동작 발생 방지
                    go_on = False      #분석 동작조건 해제
                    #print('find i.value :',i.value,'(en=',en+1,')',) -> 동작 확인용 log
                    break
                if (i.value == sn): #태깅 번호 부분 continue
                    go_on = True    #sn찾으면 작업시작 알림
                    toggle = True   #태그 만나면, 2회 행 continue 되어야 함(순번 행, 순번 아래의 숫자행은 분석X)
                    sn+=1           #태그 순번을 만났으면 
                    #print('find i.value :',i.value,'(sn=',sn-1,')',) -> 동작 확인용 log
                    continue #해당 iter skip
                if toggle:  #toggle 상태일 때 continue 한 번 더( 숫자행 부분 )
                    toggle = False
                    continue
                if go_on:   #동작 조건상태일 때
                    if (i.value != None): #행값이 비어있지 않다면
                        tmpstr = Analysis_(str(i.value))    #행데이터 분석
                        load_ws[ColumnReturn.get()+str(cnt)] = tmpstr #분석한 string을 실제 엑셀의 저장열 위치에 load
                        print(sn+'(' + ColumnReturn.get()+str(cnt) + ') => ' + tmpstr) # console창 Progress _ 현재 태그넘버 (실제 저장되는 Cell 위치) => 저장값
                        
                        #Progress update 예정 : 임시 Label 관리용
                        tmpProgress = str(sn) + '/' + str(en) 
                        Progress.text = tmpProgress
                        
                        #print(ColumnReturn.get()+str(cnt),':',tmpstr) -> 동작 확인용 log
                else: #동작조건 아닌 경우 통과
                    continue
                
            messagebox.showinfo('Finish!', '완료되었습니다!')
            Progress.text = "" #Progress 동작 종료 (임시 : OS block상태 해결하지 못해 동작하지 않음/ tkinter. progressbar 작업예정 1.5ver)
            load_wb.save(root.filename) #저장한 Workbook Save
        else:   #File_selection에서 작업을 완료하지 않거나, 종료한 경우
            messagebox.showinfo('Cancel', '작업을 취소하셨습니다.')
            
def Indivisual_Analysis():  #프로그램 하단부의 개별 문장분석부
    if (analysis.get('1.0', 'end-1c')==''):
        messagebox.showinfo('경고','개별 분석할 문장을 기입해주세요!')
    else:
        #root.grab_set() # Prevent clicking root while messagebox is open :  modal형 동작을 위한 구문 / test 필요하나, 굳이 쓸만한 기능은 아님
        #if (resultbox.get('1.0', 'end-1c')!=''):
           # ans = messagebox.askyesno('데이터 감지', '진행하시면 기존 결과값이 사라집니다!')
        #root.wait_window() # Prevent clicking root while messagebox is open
        #if ans:
            messagebox.showinfo("Alert", '품사태깅 시작')
            tmpstr = Analysis_(analysis.get('1.0', 'end-1c'))
            resultbox.delete('1.0', END)
            resultbox.insert('1.0', tmpstr)
            messagebox.showinfo('Finish!', '완료되었습니다!')
            #작업 종료 이후, resultbox 내부 텍스트 전체 블록상태로 만드는 update 필요 (그러나 자료조사 결과, scrolledText에서 블록기능을 찾기 힘듬)
#...


#tkinter GUI setting
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
ColumnCall_ = Label(root, text="분석열 Alphabet=>").grid(row=5,column=0)
ColumnCall = Entry(root)
ColumnCall.grid(row=5, column=1)
ColumnCall.insert(0, 'B')
ColumnReturn_ = Label(root, text="결과열 Alphabet=>").grid(row=6,column=0)
ColumnReturn = Entry(root)
ColumnReturn.grid(row=6, column=1)
ColumnReturn.insert(0, 'C')
do_btn = Button(root, text='  Do!  ', command=main_)
do_btn.grid(row=7, columnspan=2, sticky=W+E)
root.grid_rowconfigure(8, minsize=60)
Progress = Label(root, text="")
Progress.grid(row=8, columnspan=2, sticky=W+E+N+S)
s=tkinter.ttk.Separator(root, orient="horizontal")	
s.grid(row=9,columnspan=2, sticky=W+E+N+S)
root.grid_rowconfigure(10, minsize=50)
info1 = Label(root, text='직접 분석하기', relief='solid').grid(row=10, columnspan=2)
analysis_ = Label(root, text="개별 분석할 문장").grid(row=11, columnspan=2, stick=W+E)
root.grid_rowconfigure(12, minsize=80)
analysis = tkst.ScrolledText(root, width=30, height=3)
analysis.grid(row=12, columnspan=2, sticky=W+E+N+S)
analysis.focus_set()
indiv_do_btn = Button(root, text='분석', command=Indivisual_Analysis)
indiv_do_btn.grid(row=13, columnspan=2, sticky=W+E)
resultbox = tkst.ScrolledText(root, width=30, height=3)
root.grid_rowconfigure(14, minsize=80)
resultbox.grid(rows=14, columnspan=2, sticky=W+E+N+S)

root.mainloop()
