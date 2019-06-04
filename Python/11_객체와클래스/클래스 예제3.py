class Emp:
    pass

x = Emp()
y = Emp()

#클래스 자체 값을 결정 (기본값)
Emp.dept = 'Research'
print('xDept:', x.dept, '\tyDept:',y.dept)

#객체 자체 값을 재설정
x.dept = 'Accounting'
print('xDept:', x.dept, '\tclassDept:',Emp.dept)

#클래스 자체 값을 재설정 (기본값)
Emp.dept = 'Sales'
print('xDept:', x.dept, '\tyDept:',y.dept)

print('x.__dict__:', x.__dict__)
print('y.__dict__:',y.__dict__)