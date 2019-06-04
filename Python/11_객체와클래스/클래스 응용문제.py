class BankAcct():
    def __init__(self, iV=0): self.balance = iV
    def withdraw(self, iV):
        if self.balance-iV<0: print('인출 불가: 잔고가 부족함')
        else: self.balance-=iV
    def deposit(self, iV): self.balance+=iV
    
a = BankAcct(1000)
print(a.balance)
a.deposit(100)
print(a.balance)
a.withdraw(500)
print(a.balance)
a.withdraw(1000)