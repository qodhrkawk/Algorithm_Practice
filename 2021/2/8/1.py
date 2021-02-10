# 프로그래머스 메뉴 리뉴얼

from itertools import combinations


def solution(orders, course):
    answer = []
    myDict = {}

    for i in range(len(orders)):
        for j in range(i + 1, len(orders)):
            tmp = list(set(orders[i]) & set(orders[j]))
            tmp.sort()
            tmp = ''.join(tmp)

            if len(tmp) > 0 :
                for k in course:
                    if k <= len(tmp):
                        comb = list(combinations(tmp, k))
                        for l in range(len(comb)) :
                            key = str(''.join(comb[l]))
                            if key in myDict :
                                myDict[key] += 1
                            else :
                                myDict[key] = 1

    for c in course :
        arr = []
        maxNum = 0
        for key, value in myDict.items() :
            if len(key) == c :
                if maxNum < value :
                    arr = [key]
                    maxNum = value
                elif maxNum == value :
                    arr.append(key)
        for i in range(len(arr)):
            answer.append(arr[i])

    answer.sort()



    return answer


