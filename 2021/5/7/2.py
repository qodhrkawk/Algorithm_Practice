# 프로그래머스 스티커모으기(2)

def subSolution(sticker,dp) :

    for i in range(3,len(dp)) :
        dp[i] = max(dp[i-2],dp[i-3])+sticker[i]
    return

def solution(sticker):

    n = len(sticker)
    dp0 = [0 for _ in range(n-1)]
    dp1 = [0 for _ in range(n)]
    dp2 = [0 for _ in range(n)]

    if n == 1:
        return sticker[0]

    if n == 2 or n == 3 :
        return max(sticker)
    if n == 4 :
        return max(sticker[0]+sticker[2],sticker[1]+sticker[3])

    dp0[0] = sticker[0]
    dp0[1] = 0
    dp0[2] = sticker[2]+sticker[0]
    dp1[1] = sticker[1]
    dp1[2] = 0

    dp2[2] = sticker[2]

    subSolution(sticker,dp0)
    subSolution(sticker, dp1)
    subSolution(sticker, dp2)

    return max(max(dp0),max(dp1),max(dp2))

print(solution([14, 6, 5, 11, 3, 9, 2, 10]))