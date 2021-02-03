def solution(n):
    answer = 0

    s = ""
    while n >= 3 :
        s+= str(int(n%3))
        n = n / 3

    s+=str(int(n))

    for i in range(len(s)) :
        answer += int(s[i])*pow(3,len(s)-i-1)


    return answer
