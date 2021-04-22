import  sys
sys.setrecursionlimit(10**9)

def D(n) :
    return (2*n)%10000

def S(n):
    if n == 1 :
        return 9999
    return n-1

def L(n) :
    return int(str(n)[1:]+str(n)[0])

def R(n):
    return int(str(n)[-1]+str(n)[:-1])

answer = ""

def dfs(a,b,s,rl) :

    global answer
    if answer != "" and len(s) >= len(answer) :
        return

    if len(s) > rl :
        return

    if a == b:
        answer = s
        return
    else :

        dfs(D(a),b, s+'D',rl)
        dfs(S(a), b, s + 'S',rl)
        dfs(L(a), b, s + 'L',rl)
        dfs(R(a), b, s + 'R',rl)

    return


def solution() :
    global  answer

    t = int(input())
    for _ in range(t) :
        a,b = map(int,input().split())
        rl = 0
        while answer == "" :
            rl += 1
            dfs(a, b, "",rl)


        print(answer)
        answer = ""

solution()