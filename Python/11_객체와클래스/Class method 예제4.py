class Emp:
    def restart(self):
        self.bonus = 0
    def sale(self):
        self.bonus += 10
    def message(self):
        print(self.name + '의 보너스는', self.bonus)

a = Emp()
a.name = 'John'

a.restart()
a.sale()
a.message()