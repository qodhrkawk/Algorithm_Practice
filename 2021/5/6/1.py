# 프로그래머스 신규 아이디 추천

def solution(new_id):

    answer = new_id.lower()
    special = ["-","_","."]

    tmp = ""
    dotCount = 0
    for c in answer :
        print(dotCount)
        if not c.isalpha() :
            if c in special or c.isdigit() :
                if dotCount == 1 and c == "." :
                    continue
                elif dotCount == 0 and c == "." :
                    dotCount = 1
                else :
                    dotCount = 0
                tmp += c
        else :
            dotCount = 0
            tmp += c


    answer = tmp

    if answer[0] == "." :
        answer = answer[1:]
    if len(answer) > 0 and answer[-1] == "." :
        answer = answer[0:len(answer)-1]
    if len(answer) == 0 :
        answer = "a"
    if len(answer) > 15 :
        answer = answer[0:15]
    if len(answer) > 0 and answer[0] == "." :
        answer = answer[1:]
    if answer[-1] == "." :
        answer = answer[0:len(answer)-1]

    if len(answer) <= 2 :
        while len(answer) < 3 :
            answer += answer[-1]


    return answer