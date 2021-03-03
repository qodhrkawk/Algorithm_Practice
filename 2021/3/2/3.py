
#백준 파티

import heapq

def solution() :
    n,m,x = map(int,input().split())

    graph = [[] for _ in range(n+1)]
    graph2 = [[] for _ in range(n+1)]

    for i in range(m) :
        u,v,w = map(int,input().split())
        graph[v].append([u,w])
        graph2[u].append([v,w])

    dist = [float('inf') for _ in range(n+ 1)]
    dist2 = [float('inf') for _ in range(n + 1)]

    dist[x] = 0
    dist2[x] = 0

    queue = []

    heapq.heappush(queue,x)

    while queue :
        u = heapq.heappop(queue)
        for v in graph[u] :
            if dist[u] + v[1] < dist[v[0]] :
                dist[v[0]] = dist[u]+v[1]
                heapq.heappush(queue,v[0])

    queue = []

    heapq.heappush(queue, x)

    while queue:
        u = heapq.heappop(queue)
        for v in graph2[u]:
            if dist2[u] + v[1] < dist2[v[0]]:
                dist2[v[0]] = dist2[u] + v[1]
                heapq.heappush(queue, v[0])

    ans = 0

    for i in range(1,n+1) :
        ans = max(dist[i]+dist2[i],ans)
    return ans





print(solution())