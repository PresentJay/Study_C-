class Emp:
    def intro(self):
        print('My name is', self.name, '!')

a = Emp()
a.name = 'John'
a.intro()