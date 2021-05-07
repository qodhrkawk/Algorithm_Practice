# 파이썬 문자열 압축

def solution(s):

    n = len(s)
    answer = n


    for l in range(2,n//2,1) :
        i = 0
        cur = ""
        count = 0
        while i < n :
            if i+l < n :
                sub = s[i:i+l+1]
                if cur == "" :
                    cur = sub
                else :
                    if cur == sub :
                        count += 1
                        i += l
                    else :
                        if count != 0 :
                            answer += str(count) + cur
                        cur = sub
                        count = 0





    return answer