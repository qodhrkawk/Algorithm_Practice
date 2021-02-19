def gcd(a,b) :
    if a<b:
        a,b = b,a
    while b!= 0 :
        a,b = b,a%b
    return a

def lcm(a,b) :
    if a<b:
        a,b = b,a
    i = 1
    tmp = a
    while True:
        tmp = a*i
        if tmp % a == 0 and tmp % b == 0 :
            return tmp
        i += 1




def solution(n, m):
    answer = []
    answer.append(gcd(n,m))
    answer.append(lcm(n,m))

    return answer