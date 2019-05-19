sentence = "Time is\nToo Slow for those who wait\nToo Swift for those who Fear\nToo Long for those who Grieve\nToo Short for those who Rejoice\nBut for those who love\nTime is not"
print("문장:")
print(sentence,'\n')
dic={}
for i in set(sentence.split()):
    cnt=0
    for j in sentence.split():
        if i==j: cnt+=1
    dic[i]=cnt
for i, j in dic.items():
    print(i,':',j,'회')