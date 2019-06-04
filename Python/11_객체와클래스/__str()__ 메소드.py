class Emp:
    empTotal = 0

    def __init__(self, name, bonus=100):
        self.name = name
        self.bonus = self.base = bonus
        Emp.empTotal += 1

    def __str__(self):
        return '이름: ' + self.name + ' 보너스: ' + str(self.bonus)

    def restart(self):
        self.bonus = self.base

    def sale(self):
        self.bonus += 10
    
a = Emp('Peter', 50)
a.sale()

print(a)