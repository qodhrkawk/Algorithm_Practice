# 프로그래머스 프린터


def solution(priorities, location):
    answer = 0

    while len(priorities) :
        print(location)
        if priorities[0] == max(priorities) :
            answer += 1
            priorities.pop(0)
            if location == 0 :
                return answer
            else :
                location -= 1
        else :
            tmp = priorities.pop(0)
            priorities.append(tmp)
            if location == 0 :
                location = len(priorities)-1
            else :
                location -= 1



    return answer

print(solution([1,3,2,1],0))