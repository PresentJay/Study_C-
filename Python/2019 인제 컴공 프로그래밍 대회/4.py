r,c = map(int, input().strip().split())

queue=[[0,0]]
container=[]
curFire=[]
for i in range(r):
    container.append(input())

def tic(x, y):
    if container[max(x+1,r-1)][y]=='.' and container[max(x+1,r-1)][y]!='#':
        container[max(x+1,r-1)][y]='@'
    if container[x-1][y]=='.' and container[x-1][y]!='#':
        container[x-1][y]='@'
    if container[x][max(y+1,r-1)]=='.' and container[x][max(y+1,r-1)]!='#':
        container[x][max(y+1,r-1)]='@'
    if container[x][y-1]=='.' and container[x][y-1]!='#':
        container[x][y-1]='@'
    if container[max(x+1,r-1)][y]=='&' or container[x-1][y]=='&' or container[x][max(y+1,r-1)]=='&' or container[x][y-1]=='&':
        return True
    return False

def fireMyongSeok():
    for i in range(r):
        for j in range(r):
            if container[i][j]=='@':
                tic(i,j)

def printer():
    for i in container:
        print(i)

printer()
fireMyongSeok()
printer()
