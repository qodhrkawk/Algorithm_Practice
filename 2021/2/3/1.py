# 프로그래머스 1단계 모의고사

def solution(answers):
    answer = []

    first = [1,2,3,4,5]
    second = [2,1,2,3,2,4,2,5]
    third = [3,3,1,1,2,2,4,4,5,5]

    corrects = [0,0,0]

    for i in range(len(answers)) :
        if first[i%5] == answers[i] :
            corrects[0] += 1
        if second[i%8] == answers[i] :
            corrects[1] += 1
        if third[i%10] == answers[i] :
            corrects[2] += 1
    maximum = 0
    for i in range(3) :
        if corrects[i] > maximum :
            answer = []
            answer.append(i+1)
            maximum = corrects[i]
        elif corrects[i] == maximum :
            answer.append(i+1)






    return answer