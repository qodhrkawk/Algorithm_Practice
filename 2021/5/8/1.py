from _collections import defaultdict


def solution(s):
    answer = ""
    dic = defaultdict(int)


    dic = {"zero":0,"one":1,"two":2,"three":3,"four":4,"five":5,"six":6,"seven":7,"eight":8,"nine":9}

    tmp = ""


    for idx,c in enumerate(s) :
        if c.isdigit() :
            answer += c
        else :
            tmp+= c
            if tmp in dic :
                answer += str(dic[tmp])
                tmp = ""






    return int(answer)

solution("ss")