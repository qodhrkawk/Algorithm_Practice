#프로그래머스 큰 수 만들기


def solution(number, k):
    answer = ''

    start = 0
    while k > 0 :
        was = start
        for i in range(was,was+k) :
            if number[was+i] > number[was+start] :
                start = i

        k -= start - was



    return answer


#
print(solution("1924",2))