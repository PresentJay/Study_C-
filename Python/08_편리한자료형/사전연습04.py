#사전 갱신방법
grade = {"eng":87, "math":98}
grade["sci"] = 95
print(grade)

grd = {"kor":87}
grade.update(grd)
print(grade)