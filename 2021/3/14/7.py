#백준 특정한 최단 경로

from _collections import deque
import heapq

def solution() :

    n,m = map(int,input().split())
    INF = float('inf')

    graph = [[] for _ in range(n+1)]
    dist = [INF for _ in range(n+1)]
    dist1 = [INF for _ in range(n + 1)]
    dist2 = [INF for _ in range(n + 1)]






    for _ in range(m) :
        u,v,w = map(int,input().split())
        graph[u].append([v,w])
        graph[v].append([u, w])


    v1, v2 = map(int, input().split())

    dist[1] = 0

    queue = []
    heapq.heappush(queue,1)

    while queue :
        u = heapq.heappop(queue)

        for v in graph[u] :
            if dist[v[0]] > dist[u] + v[1] :
                dist[v[0]] = dist[u] + v[1]
                heapq.heappush(queue,v[0])


    dist1[v1] = 0
    queue = []
    heapq.heappush(queue, v1)

    while queue:
        u = heapq.heappop(queue)

        for v in graph[u]:
            if dist1[v[0]] > dist1[u] + v[1]:
                dist1[v[0]] = dist1[u] + v[1]
                heapq.heappush(queue, v[0])


    dist2[v2] = 0
    queue = []
    heapq.heappush(queue, v2)

    while queue:
        u = heapq.heappop(queue)

        for v in graph[u]:
            if dist2[v[0]] > dist2[u] + v[1]:
                dist2[v[0]] = dist2[u] + v[1]
                heapq.heappush(queue, v[0])

    ans = min(dist[v1]+dist1[v2]+dist2[n],dist[v2]+dist2[v1]+dist1[n])
    if ans == INF :
        return -1
    return ans

print(solution())