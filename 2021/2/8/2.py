#프로그래머스 이진 변환 반복하기


def solution(s):
    iters = 0
    zeros = 0
    while s != '1' :
        iters += 1
        zeros += s.count('0')
        s = s.replace('0','')
        digit = int(len(s))
        binary = ''
        while digit > 0 :
            binary = str(digit%2) + binary
            digit //= 2

        s = binary


    answer = [iters,zeros]
    return answer

print(solution("110010101001"))