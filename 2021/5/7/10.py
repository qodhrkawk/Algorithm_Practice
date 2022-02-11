
a,b = 0,0
answer = ""

def subSolution(s) :

    global a,b,answer

    if a > b :
        if a >= 2 :
            a -= 2
            answer += "aa"
        elif a == 1 :
            a -= 1
            answer += "a"
    elif a == 0 and b == 0 :
        answer += ""
    else :
        if b >= 2 :
            b -= 2
            answer += "bb"
        elif b == 1 :
            b -= 1
            answer += "b"



def solution(A,B):

    global a,b,answer

    a,b = A,B

    while a > 0 and b > 0 :
        print(a,b,answer)
        subSolution("")


    return answer


print(solution(2,3))