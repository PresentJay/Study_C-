def intro(emp):
    print('My name is', emp.name, '!')

class Emp:
    myIntro = intro

a = Emp()
a.name = 'John'
Emp.myIntro(a)