#프로그래머스 줄 서는 방법

from itertools import permutations



def solution(n, k):
    answer = []

    people = [i for i in range(1,n+1)]

    factorial = [0,1]

    for i in range(2,21) :
        factorial.append(factorial[i-1]*i)

    idx = 0
    while k > 0 and len(people) > 0:
        print(people)
        print(k)
        if factorial[len(people)-1] > k :
            k -= factorial[len(people)]
            idx += 1
        else :
            answer.append(people[idx])
            del people[idx]
            idx = 0







    return answer


print(solution(3,5))