from _collections import deque


def solution(n, k, cmd):
    answer = ''

    arr = [True for _ in range(n)]
    nexts = [i+1 for i in range(n)]
    befores = [i-1 for i in range(n)]
    curIdx = k
    delIndices = deque()
    for cm in cmd :
        c = cm.split()

        if c[0] == "D" :
            for _ in range(int(c[1])) :
                curIdx = nexts[curIdx]

        elif c[0] == "U" :
            for _ in range(int(c[1])):
                curIdx = befores[curIdx]


        elif c[0] == "C":
            arr[curIdx] = False


            if befores[curIdx] != 0 :
                nexts[befores[curIdx]] = nexts[curIdx]

            if nexts[curIdx] != n :
                befores[nexts[curIdx]] = befores[curIdx]

            delIndices.append(curIdx)

            if nexts[curIdx] >= n :
                curIdx = befores[curIdx]
            else :
                curIdx = nexts[curIdx]

        else :
            tmp = delIndices.pop()
            arr[tmp] = True
            if befores[tmp] != -1 :
                nexts[befores[tmp]] = tmp
            if nexts[tmp] < n :
                befores[nexts[tmp]] = tmp

    for i in range(n) :
        if arr[i] :
            answer += "O"
        else :
            answer += "X"

    return answer

print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z"]))