# 프로그래머스 N으로 표현


def solution(N, number):


    if N == number :
        return 1

    digits = [[],[N]]

    for i in range(2,9):
        tmp = [int(str(N)*i)]
        for j in range(1,i//2+1) :
            for d in digits[j] :
                for k in digits[i-j] :

                    if d!= 0 and k != 0:
                        tmp.append(d+k)
                        tmp.append(d*k)
                        if d > k :
                            tmp.append(d-k)
                            tmp.append(d//k)
                        else :
                            tmp.append(k-d)
                            if k//d != 0 :
                                tmp.append(k//d)

        digits.append(tmp)

        if number in tmp :
            return i

    return -1

print(solution(5,12))