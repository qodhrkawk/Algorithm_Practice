#백준 스도쿠

def getIndex(x,y) :
    ans = (int(x/3)*3,int(y/3)*3)
    return ans

def solution() :
    mylist = [list(map(int, input().split())) for _ in range(9)]

    holes = []
    candidates = []

    for i in range(len(mylist)) :
        for j in range(len(mylist)) :
            if mylist[i][j] == 0 :
                holes.append((i,j))

    for k in range(len(holes)) :
        candidates.append(list(map(int,[1,2,3,4,5,6,7,8,9])))
        shouldRemove = []
        for i in range(9) :
            if mylist[i][holes[k][1]] == 0 :
                continue
            shouldRemove.append(mylist[i][holes[k][1]])

        for rem in shouldRemove:
            candidates[k].remove(rem)

        shouldRemove = []
        for j in range(len(candidates[k])) :

            if candidates[k][j] in mylist[holes[k][0]] :
                shouldRemove.append(candidates[k][j])
        for rem in shouldRemove:
            candidates[k].remove(rem)
        shouldRemove = []

        tup = getIndex(holes[k][0],holes[k][1])
        for x in range(len(candidates[k])) :
            for i in range(tup[0],tup[0]+3):
                for j in range(tup[1],tup[1]+3):
                    if candidates[k][x] == mylist[i][j] :
                        shouldRemove.append(candidates[k][x])
        for rem in shouldRemove:
            candidates[k].remove(rem)

    for i in range(len(holes)) :
        mylist[holes[i][0]][holes[i][1]] = candidates[i][0]

    for i in range(9) :
        for j in range(9):
            print(mylist[i][j],end=" ")
        print("")



solution()
