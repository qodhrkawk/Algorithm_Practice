import heapq
def solution(scoville, K):
    answer = 0

    pq = []
    for i in range(len(scoville)) :
        heapq.heappush(pq,scoville[i])

    while pq[0] < K :
        answer += 1
        if len(pq) == 1 :
            return -1
        least = heapq.heappop(pq)
        least2 = heapq.heappop(pq)
        heapq.heappush(pq,least+least2*2)
    return answer

