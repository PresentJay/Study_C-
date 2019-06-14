def listmax(lst):
    max=0
    for i in lst:
        if i>max: max=i
    return max
lst = [28, 13, 76, 32, 63]
print(lst, 'max', listmax(lst))
