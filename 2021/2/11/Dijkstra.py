#프로그래머스 합승 택시 요금

import heapq

def relax(u,v,w,dist) :
    if dist[v] > dist[u] + w :
        dist[v] = dist[u] + w


def solution(n, s, a, b, fares):
    answer = 0

    dist = [float('inf') for _ in range(n+1)]
    dist[s] = 0
    heap = []
    graph = [[] for _ in range(n+1)]

    for fare in fares :
        graph[fare[0]].append([fare[1],fare[2]])
        graph[fare[1]].append([fare[0], fare[2]])

    for i in range(n) :
        heapq.heappush(heap,(dist[i],i))

    while heap :
        u = heapq.heappop(heap)

        for v in graph[u[1]] :
            relax(u[1],v[0],v[1],dist)

    


    return answer



print(solution(6,4,6,2,[[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]]))