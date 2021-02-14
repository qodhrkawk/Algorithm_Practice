#프로그래머스 배달
import heapq




def solution(N, road, K):
    answer = 0

    graph = [[] for _ in range(N+1)]

    for r in road :
        graph[r[0]].append((r[1],r[2]))
        graph[r[1]].append((r[0], r[2]))

    dist = [float('inf') for _ in range(N+1)]
    dist[1] = 0

    heap = []
    heapq.heappush(heap,1)

    while heap:
        u = heapq.heappop(heap)

        for v in graph[u]:
            if dist[v[0]] > dist[u] + v[1] :
                dist[v[0]] = dist[u] + v[1]
                heapq.heappush(heap,v[0])


    for i in range(1,N+1) :
        if dist[i] <= K :
            answer += 1





    return answer



print(solution(5,[[1,2,1],[2,3,3],[5,2,2],[1,4,2],[5,3,1],[5,4,2]],3))
print(solution(6,[[1,2,1],[1,3,2],[2,3,2],[3,4,3],[3,5,2],[3,5,3],[5,6,1]],4))