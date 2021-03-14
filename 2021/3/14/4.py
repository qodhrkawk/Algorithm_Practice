#백준 단지번호붙이기

from _collections import defaultdict
from _collections import deque
import copy

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

            if 0 <= newY < len(map) and 0 <= newX < len(map) and map[newY][newX] > 0 :
                map[newY][newX] = num
                queue.append([newY,newX])

def solution() :
    n = int(input())

    myMap = []
    heights = [[] for _ in range(101)]

    for _ in range(n):
        tmp = list(map(int,input().split()))
        myMap.append(tmp)

    for i in range(n) :
        for j in range(n) :
            heights[myMap[i][j]].append([i,j])

    answer = 1

    for i in range(101) :
        if len(heights[i]) > 0 :
            for h in heights[i] :
                myMap[h[0]][h[1]] = 0

            tmpMap = copy.deepcopy(myMap)

            cnt = -1
            for y in range(n) :
                for x in range(n) :
                    if tmpMap[y][x] > 0 :
                        makeSep(tmpMap,y,x,cnt)
                        cnt -= 1
            answer = max(answer,abs(cnt+1))


    print(answer)


solution()


