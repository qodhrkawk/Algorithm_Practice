#프로그래머스 최고의 집합


def solution(n, s):
    answer = []

    p = s//n
    q = s%n

    if n > s :
        return [-1]

    for i in range(n) :
        answer.append(p)

    for j in range(q) :
        answer[-1-j] += 1

    answer = sorted(answer)


    return answer


print(solution(4,30))