#프로그래머스 보석 쇼핑

def solution(gems):

    dict = {}
    mySet = list(set(gems))
    tmpSet = set()
    trash = []

    for s in mySet:
        dict[s] = 0


    start,end = 0,0
    n = len(gems)
    m = len(mySet)


    answer = []
    while True :
        #조건 만족


        if len(tmpSet) == m and start < end :

            if dict[gems[start]] == 1 :
                tmpSet.remove(gems[start])
                trash.append(gems[start])

            dict[gems[start]] -= 1
            start += 1


        elif end == n :
            break
        else :
            if gems[end] not in tmpSet :
                # tmpSet.append(gems[end])
                tmpSet.add(gems[end])
            dict[gems[end]] += 1
            end += 1



        if len(tmpSet) == m :
            if len(answer) == 0 :
                answer = [start+1,end]
            else :
                if end-(start+1) < answer[1]-answer[0] :
                    answer = [start+1,end]




    return answer


print(solution(["DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA"]))