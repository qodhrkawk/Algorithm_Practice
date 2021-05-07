def solve(p) :
    if len(p) == 0 :
        return ""

    u,v = sep(p)
    print(u)
    print(v)

    if checkCorrect(u) :
        return u+solve(v)
    else :
        tmp = "(" + solve(v) + ")"
        uTmp = ""
        for i in range(1,len(u)-1) :
            if u[i] == "(" :
                uTmp += ")"
            else :
                uTmp += "("
        return tmp + uTmp

def sep(s) :
    u,v = "",""

    leftCount = 0
    for idx,c in enumerate(s) :
        u += c
        if c == "(" :
            leftCount += 1
        else :
            leftCount -= 1

        if leftCount == 0 :
            v = s[idx+1:]
            break


    return u,v


def checkCorrect(s) :
    stack = []

    for c in s :
        if c == "(" :
            stack.append("(")
        else :
            if stack :
                stack.pop(-1)
            else :
                return False
    return True

def solution(p):

    return solve(p)


print(solution("()))((()"))