#프로그래머스 야근 지수
import heapq

def solution(n, works):
    answer = 0


    queue = sorted(works,reverse=True)

    for idx in range(len(queue)) :
        queue[idx] = -queue[idx]


    while n > 0 :
        tmp = heapq.heappop(queue)
        tmp += 1
        n -= 1
        heapq.heappush(queue,tmp)



    for q in queue :
        if q < 0 :
            answer += pow(q,2)


    return answer


print(solution(4,[4,3,3]))