    #백준 적록색약

from _collections import deque
import copy

def makeSep(arr,i,j,name) :

    d = [[0,1],[0,-1],[1,0],[-1,0]]

    arr[i][j] = 'V'

    queue = deque()
    queue.append([i,j])


    while queue :
        front = queue.popleft()
        y,x= front[0],front[1]

        for i in range(4) :
            newY = y+d[i][0]
            newX = x+d[i][1]

            if 0 <= newY < len(arr) and 0 <= newX < len(arr) and arr[newY][newX] == name :

                arr[newY][newX] = 'V'
                queue.append([newY,newX])






def solution() :

    n = int(input())

    arr = []
    for _ in range(n) :
        line = str(input())
        tmp = []
        for l in line :
            tmp.append(l)
        arr.append(tmp)

    arr2 = copy.deepcopy(arr)

    for i in range(n):
        for j in range(n) :
            if arr2[i][j] == 'G' :
                arr2[i][j] = 'R'

    answer = [0,0]
    for i in range(n) :
        for j in range(n) :
            if arr[i][j] != 'V' :
                makeSep(arr,i,j,arr[i][j])
                answer[0] += 1
            if arr2[i][j] != 'V' :
                makeSep(arr2,i,j,arr2[i][j])
                answer[1] += 1
    print(answer[0],end= " ")
    print(answer[1])

    return answer


solution()