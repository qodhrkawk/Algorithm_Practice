#프로그래머스 정수 삼각형


def solution(triangle):
    answer = 0

    dp = [[] for _ in range(len(triangle))]
    for i in range(len(dp)) :
        for j in range(len(triangle[i])) :
            dp[i].append(0)

    dp[0] = triangle[0]

    for i in range(1,len(dp)) :
        for j in range(len(dp[i])) :
            if j == 0 :
                dp[i][j] = max(dp[i][j],dp[i-1][j]+triangle[i][j])
            elif j == i :
                dp[i][j] = max(dp[i][j], dp[i - 1][j-1] + triangle[i][j])
            else :
                dp[i][j] = max(dp[i][j], dp[i - 1][j-1] + triangle[i][j],dp[i - 1][j] + triangle[i][j])


    answer = max(dp[-1])


    return answer