#백준 단지번호붙이기

from _collections import deque
from _collections import defaultdict

def makeSep(map,y,x,num) :

    d = [[0,1],[0,-1],[1,0],[-1,0]]

    queue = deque()
    queue.append([y,x])

    map[y][x] = num

    while queue :
        front = queue.popleft()

        y = front[0]
        x = front[1]

        for i in range(4) :
            newY = y+d[i][0]
            newX = x+d[i][1]

            if 0 <= newY < len(map) and 0 <= newX < len(map) and map[newY][newX] == 1 :
                map[newY][newX] = num
                queue.append([newY,newX])




def solution() :
    n = int(input())

    arr = []
    for _ in range(n) :
        arr.append(input())

    map = []

    for i in range(n) :
        tmp = []
        for a in arr[i] :
            tmp.append(int(a))

        map.append(tmp)

    num = 2

    for i in range(n) :
        for j in range(n) :
            if map[i][j] == 1 :
                makeSep(map,i,j,num)
                num += 1

    dict = defaultdict(int)
    for i in range(n) :
        for j in range(n) :
            if map[i][j] > 0 :
                dict[map[i][j]] += 1

    val = dict.values()
    val = sorted(val)
    print(len(val))
    for v in val :
        print(v)




solution()
