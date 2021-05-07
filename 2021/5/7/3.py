# 프로그래머스 뉴스 클러스터링


def findCommon(a,b) :

    answer = 0

    for i in range(len(a)) :
        if len(b) == 0 :
            return answer
        if a[i] in b :
            answer += 1
            b.remove(a[i])
    return answer


def solution(str1, str2):
    answer = 0
    str1 = str1.lower()
    str2 = str2.lower()

    a = []
    b = []


    for i in range(len(str1)-1) :
        if str1[i:i+2].isalpha() :
            a.append(str1[i:i+2])
    for i in range(len(str2)-1) :
        if str2[i:i + 2].isalpha():
            b.append(str2[i:i+2])
    print(a,b)

    total = len(a) + len(b)
    common = findCommon(a,b)

    total -= common
    if total == 0 :
       return 65536

    return int(float(common/total)*65536)


print(solution("FRANCE","french"))
print(solution("aa1+aa2","AAAA12"))
print(solution("E=M*C^2","e=m*c^2"))