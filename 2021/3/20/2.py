def solution(inp_str):
    answer = []

    special = '~!@#$%^&*'

    # number 1
    if len(inp_str) < 8 or len(inp_str) > 15 :
        answer.append(1)

    ascArr = [0 for _ in range(128)]

    rules = [0,0,0,0]
    prev = ''
    prevCount = 1
    for s in inp_str :
        ascArr[ord(s)] += 1
        if ascArr[ord(s)] >= 5 :
            if 5 not in answer:
                answer.append(5)

        if prev == '' :
            prev = s
        else :
            if prev == s :
                prevCount += 1
                if prevCount >= 4 :
                    if 4 not in answer :
                        answer.append(4)
            else :
                prev = s
                prevCount = 1

        if 48<= ord(s) <= 57 :
            rules[2] += 1
        elif 65 <= ord(s) <= 90 :
            rules[0] += 1
        elif 97 <= ord(s) <= 122 :
            rules[1] += 1
        elif s in special :
            rules[3] += 1
        else :
            if 2 not in answer :
                answer.append(2)

    # number 3
    count = 0
    for i in range(4) :
        if rules[i] > 0 :
            count += 1
    if count < 3 :
        answer.append(3)

    answer = sorted(answer)

    if len(answer) == 0 :
        answer.append(0)



    return answer