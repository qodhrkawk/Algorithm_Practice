#프로그래머스 가장 긴 펠린드롬


def palin(s) :
    return s == s[::-1]

def solution(s):
    answer = -1

    for i in range(len(s)) :
        for j in range(i,len(s)+1) :
            if palin(s[i:j]) :
                answer = max(len(s[i:j]),answer)

    return answer



print(solution("abcdcba"))