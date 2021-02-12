#프로그래머스 다스크 컨트롤러
import heapq

def solution(jobs):
    answer = 0



    dp = [[] for _ in range(2001)]

    for job in jobs :
        dp[job[0]].append(job[1])

    pastTime = 0
    curTime = 0
    count = 0
    queue = []


    while count < len(jobs) :
        if curTime < 2001 :
            for i in range(pastTime, curTime + 1):
                for j in range(len(dp[i])) :
                    heapq.heappush(queue, [dp[i][j],i])

        if len(queue) == 0 :
            curTime += 1
            pastTime = curTime
            continue

        front = heapq.heappop(queue)
        pastTime = curTime+1
        answer += curTime-front[1]+front[0]
        curTime += front[0]
        count += 1


    return answer//len(jobs)



print(solution([[0, 3], [1, 9], [2, 6]]))