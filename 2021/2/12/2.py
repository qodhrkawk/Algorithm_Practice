#프로그래머스 거스름돈


def solution(n, money):

    dp = [0 for _ in range(n+1)]
    dp[0] = 1
    for mon in money :
        for i in range(mon,n+1) :
            dp[i] += dp[i-mon]

    return dp[n]

print(solution(5,[1,2,5]))