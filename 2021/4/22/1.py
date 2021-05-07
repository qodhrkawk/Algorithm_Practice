
from _collections import deque

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



def solution() :

    answer = ""


    t = int(input())
    for _ in range(t) :
        visited = [False for _ in range(10001)]
        a,b = map(int,input().split())
        queue = deque()
        queue.append([a,""])

        while queue :
            front = queue.popleft()
            now,s = front[0],front[1]

            if D(now) == b :
                answer = s + "D"
                break
            if S(now) == b:
                answer = s + "S"
                break
            if L(now) == b:
                answer = s + "L"
                break
            if R(now) == b:
                answer = s + "R"
                break



            if not visited[D(now)] :
                visited[D(now)] = True
                queue.append([D(now),s+"D"])
            if not visited[S(now)]:
                visited[S(now)] = True
                queue.append([S(now), s + "S"])
            if not visited[L(now)]:
                visited[L(now)] = True
                queue.append([L(now), s + "L"])
            if not visited[R(now)]:
                visited[R(now)] = True
                queue.append([R(now), s + "R"])



        print(answer)
        answer = ""

print(R(1000))
solution()