
def solution(land):

    n = len(land)

    dp = [[0 for _ in range(4)] for _ in range(n)]


    for i in range(n-1,-1,-1):
        for j in range(4):
            if i == n-1:
                dp[i][j] = land[i][j]
            else :
                for k in range(4) :
                    if k == j :
                        continue
                    else :
                        dp[i][j] = max(dp[i][j],dp[i+1][k])

                dp[i][j] += land[i][j]

    return max(dp[0])


print(solution([[1,2,3,5],[5,6,7,8],[4,3,2,1]]))