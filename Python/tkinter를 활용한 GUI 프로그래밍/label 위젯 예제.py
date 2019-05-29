from tkinter import *
window = Tk()

lb = Label(window, text="Hello GUI World!")
lb.pack()   #lb 레이블을 windows의 화면에 배치함

window.mainloop()  #이벤트를 처리하고, 이벤트 루프에서 대기하는 메소드