from _collections import deque


def solution(n, k, cmd):
    answer = ''

    arr = [i for i in range(n)]
    curIdx = k
    deleted = deque()

    for cm in cmd:
        c = cm.split()

        if c[0] == "D":
            curIdx += int(c[1])

        elif c[0] == "U":
            curIdx -= int(c[1])

        elif c[0] == "C":
            deleted.append(arr.pop(curIdx))
            if curIdx == len(arr):
                curIdx -= 1

        else:
            tmp = deleted.pop()
            # print(tmp)
            flag = False
            for i in range(len(arr)):
                if tmp < arr[i]:
                    arr.insert(i, tmp)
                    if i < curIdx :
                        curIdx += 1
                    flag = True
                    break
            if not flag:
                arr.append(tmp)

        # print(arr,curIdx)

    for i in range(n):
        if i in arr:
            answer += "O"
        else:
            answer += "X"

    return answer


print(solution(8,2,["D 2","C","U 3","C","D 4","C","U 2","Z","Z","U 1","C"]))