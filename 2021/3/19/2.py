#프로그래머스 압축

from _collections import defaultdict

def solution(msg):
    answer = []

    dic = defaultdict(int)
    for i in range(26) :
        dic[chr(65+i)] = i+1

    lastIdx = 26


    i = 0
    tmp = ''
    while i < len(msg) :
        check = tmp + msg[i]
        if check in dic :
            tmp += msg[i]
            i += 1

        else :
            dic[check] = lastIdx+1
            lastIdx += 1
            answer.append(dic[tmp])
            tmp = ''

    answer.append(dic[tmp])

    print(dic)




    return answer

print(solution("TOBEORNOTTOBEORTOBEORNOT"))