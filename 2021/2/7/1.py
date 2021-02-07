#프로그래머스 위장

def solution(clothes):
    answer = 1

    cDict = {}

    for cloth in clothes :
        if cloth[1] in cDict :
            cDict[cloth[1]] += 1
        else :
            cDict[cloth[1]] = 1

    for val in cDict.values() :
        answer *= val+1


    return answer-1

