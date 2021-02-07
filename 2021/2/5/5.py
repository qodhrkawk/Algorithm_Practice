#프로그래머스 H-index

def solution(citations):
    answer = 0

    dp = [0 for _ in range(10002)]

    citations.sort()
    for i in range(len(citations)) :
        dp[citations[i]] += 1

    for i in range(10000,0,-1) :
        dp[i] += dp[i+1]

    for i in range(10001) :
        if dp[i] >= i :
            answer = i

    return answer
