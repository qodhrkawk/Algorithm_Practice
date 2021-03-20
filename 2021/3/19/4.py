#프로그래머스 짝수 행 세기

from itertools import combinations
from itertools import product

def solution(a):
    answer = 0

    m = len(a)
    n = len(a[0])

    candidate = [i for i in range(m)]


    ones = []

    for j in range(n) :
        count = 0
        for i in range(m) :
            if a[i][j] == 1 :
                count += 1

        ones.append(count)

    arrays = []
    for one in ones :
        comb = list(combinations(candidate,one))
        arrays.append(comb)

    for elements in product(*arrays) :
        checks = [0 for _ in range(m)]
        for elem in elements :
            for e in elem :
                checks[e] += 1
        flag = True
        for c in checks :
            if c%2 == 1 :
                flag = False
        if flag :
            answer += 1


    return answer%(10**17+19)


print(solution([[1,0,0,1,1],[0,0,0,0,0],[1,1,0,0,0],[0,0,0,0,1]]	))