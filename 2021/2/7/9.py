def solution(s):
    answer = ''
    tmp = ''
    for i in range(len(s)):
        if s[i] == ' ' :
            tmp = tmp.capitalize()
            answer += tmp + ' '
            tmp = ''
        else :
            tmp += s[i]

    tmp = tmp.capitalize()
    answer += tmp
    return answer