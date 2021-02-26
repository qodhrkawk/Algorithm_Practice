#프로그래머스 도둑질



def solution(money):

    lastAble = [0] * len(money)
    lastDisAble = [0] * len(money)

    lastDisAble[0] = money[0]
    lastDisAble[1] = money[0]

    for i in range(2,len(money)-1) :
        lastDisAble[i] = max(lastDisAble[i-1],lastDisAble[i-2]+money[i])

    lastAble[1] = money[1]

    for i in range(2, len(money)):
        lastAble[i] = max(lastAble[i - 1], lastAble[i - 2] + money[i])



    return max(lastDisAble[len(money)-2],lastAble[len(money)-1])


print(solution([1, 2, 3, 1]))