#프로그래머스 소수 찾기

from itertools import permutations



def solution(numbers):
    answer = 0
    maximum = 10000000

    perm = []

    for i in range(1,len(numbers)+1):
        for j in permutations(list(numbers),i) :
            num = int(''.join(j))
            flag = True
            for k in range(2,num) :
                if num%k == 0 :
                    flag = False
                    break
            if flag :
                if num not in perm and num != 0 and num != 1 :
                    perm.append(num)
    return len(perm)




print(solution("17"))