

import heapq

n,m = map(int,input().split())

s = int(input())
graph = [[] for _ in range(n+1)]

for _ in range(m) :
    u,v,w = map(int,input().split())
    graph[u].append([v,w])


INF = float('inf')
dist = [INF for _ in range(n+1)]

dist[s] = 0

queue = []
heapq.heappush(queue,[0,s])

while queue :
    front = heapq.heappop(queue)
    u = front[1]

    for node in graph[u] :
        if dist[u] + node[1] < dist[node[0]] :
            dist[node[0]] = dist[u] + node[1]
            heapq.heappush(queue,[dist[u]+node[1],node[0]])


for i in range(1,n+1) :
    if dist[i] == INF :
        print("INF")
    else :
        print(dist[i])

