#프로그래머스 하노이의 탑
answer = []

def move(n,start,end) :
    answer.append([start,end])

def hanoi(n,start,end,via) :
    if n == 1 :
        move(n,start,end)
    else :
        hanoi(n-1,start,via,end)
        move(n,start,end)
        hanoi(n-1,via,end,start)


def solution(n):

    hanoi(n,1,3,2)
    return answer

print(solution(2))