# boj 최단경로

import sys
import heapq

input = sys.stdin.readline


def solution():
    n,m = map(int,input().split())

    start = int(input())

    graph = [[] for _ in range(n+1)]

    for _ in range(m) :
        u,v,w = map(int,input().split())
        graph[u].append([v,w])


    dist = [float('inf') for _ in range(n+1)]
    dist[start] = 0

    heap = []
    heapq.heappush(heap,[0,start])

    while heap:
        u = heapq.heappop(heap)

        for v in graph[u[1]]:
            newW = dist[u[1]] + v[1]
            if dist[v[0]] > newW :
                dist[v[0]] = newW
                heapq.heappush(heap,[newW,v[0]])

    for i in range(1,n+1) :
        if dist[i] == float('inf') :
            print('INF')
            continue
        print(dist[i])

solution()