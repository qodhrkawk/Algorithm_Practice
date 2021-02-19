#프로그래머스 야근 지수
import heapq

def solution(n, works):
    answer = 0



    works = sorted(works,reverse=True)


    idx = 1
    while n > 0 :
        print(works)
        for i in range(idx) :

            if n > works[i] - works[idx] :
                works[i] = works[idx]
                n -= works[i] - works[idx]
            else :
                works[i] -= n
                n = 0
        idx += 1
        if idx == len(works)-1 and n > 0:
            works[idx] -= 1
            n -= 1
            idx -= 1




    return answer



print(solution(4,[4,3,3]))