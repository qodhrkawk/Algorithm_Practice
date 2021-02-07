#프로그래머스 소수 찾기

def solution(numbers):
    answer = 0
    maximum = 10000000
    maximum = 10

    dp = [True for _ in range(maximum)]

    dp[0] = False
    dp[1] = False

    for i in range(2,maximum) :
        for j in range(2,i*j<maximum,1) :
            dp[i*j] = False

    for i in range(2, maximum):
        if set(str(i)) - set(numbers) <= 0 :
            answer += 1


    print(dp)
    return answer

print(solution("123"))