# 프로그래머스 쿼드압축 후 개수 세기

zero = 0
one = 0

gArr = []

def div(size,y,x) :

    global zero
    global one
    tmp = gArr[y][x]
    for i in range(size) :
        for j in range(size) :
            if gArr[y+i][x+j] != tmp :
                div(size//2,y,x)
                div(size // 2, y+size//2, x)
                div(size // 2, y, x+size//2)
                div(size // 2, y+size//2, x+size//2)
                return

    if tmp == 0 :
        zero += 1
    else :
        one += 1

    return


def solution(arr):
    global gArr
    gArr = arr
    div(len(arr),0,0)


    return [zero,one]

print(solution([[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]))