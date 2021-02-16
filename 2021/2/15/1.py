#프로그래머스 N으로 표현


def solution(N, number):
    answer = 0

    max = 32001

    dp = [float('inf') for _ in range(max)]
    dp[N] = 1


    queue = [N]

    while queue :
        front = queue.pop(0)

        if front/N > 0 and dp[int(front/N)] > dp[front]+1 :
            queue.append(int(front/N))
            dp[int(front/N)] = dp[front] + 1
        if front*N < max and dp[front*N] > dp[front]+1 :
            queue.append(front*N)
            dp[front*N] = dp[front] + 1
        if front+N < max and dp[front+N] > dp[front]+1 :
            queue.append(front+N)
            dp[front+N] = dp[front] + 1
        if front-N > 0 and dp[front-N] > dp[front]+1 :
            queue.append(front-N)
            dp[front-N] = dp[front] + 1
        if front*10 + N < max and dp[front*10 +N] > dp[front]+1 :
            queue.append(front*10+N)
            dp[front*10+N] = dp[front] + 1



    answer = dp[number]
    if answer > 8 :
        answer = - 1



    
    return answer



print(solution(2,11))