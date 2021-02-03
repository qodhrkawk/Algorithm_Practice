#프로그래머스 2016년

def solution(a, b):
    answer = ''

    arr = ['SUN','MON','TUE','WED','THU','FRI','SAT']
    dates = [31,28,31,30,31,30,31,31,30,31,30,31]

    distance = b
    for i in range(a-1) :
        distance += dates[i]

    answer = arr[(distance+5)%7]


    return answer