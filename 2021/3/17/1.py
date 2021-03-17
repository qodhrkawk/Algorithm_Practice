#프로그래머스 기둥과 보 설치


def checkImpossible(result) :
    for x,y,a in result :
        if a == 0 :
            if y != 0 and (x,y-1,0) not in result and (x-1,y,1) not in result \
                    and (x,y,1) not in result :
                return True

        else :
            if (x,y-1,1) not in result and (x+1,y-1,0) not in result and \
                    not ((x-1, y, 1) in result and (x+1, y, 1) in result):
                return True
    return False




def solution(n, build_frame):


    result = set()

    for x,y,a,build in build_frame :
        event = (x,y,a)

        if build == 1 :
            result.add(event)
            if checkImpossible(result) :
                result.remove(event)
        elif event in result :
            result.remove(event)
            if checkImpossible(result) :
                result.add(event)



    answer = map(list, result)

    return sorted(answer, key=lambda x: (x[0], x[1], x[2]))


print(solution(5,[[1,0,0,1],[1,1,1,1],[2,1,0,1],[2,2,1,1],[5,0,0,1],[5,1,0,1],[4,2,1,1],[3,2,1,1]]))