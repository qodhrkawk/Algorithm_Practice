
import heapq
from _collections import defaultdict


def solution(n, start, end, roads, traps):

    graph = [[[] for _ in range(n+1)] for _ in range(n + 1)]

    for road in roads :
        graph[road[0]][road[1]].append(road[2])
        graph[road[1]][road[0]].append(-road[2])


    for i in range(n+1) :
        for j in range(n+1) :
            tmp = []
            if len(graph[i][j]) > 0 :
                minimum = 3001
                maximum = -3001

                for w in graph[i][j] :
                    if minimum > w and w > 0:
                        minimum = w
                    if maximum < w and w < 0 :
                        maximum = w
                if minimum != 3001 :
                    tmp.append(minimum)
                if maximum != -3001 :
                    tmp.append(maximum)

                graph[i][j] = tmp


    dist = [float('inf') for _ in range(n + 1)]
    dist[start] = 0

    heap = []

    heapq.heappush(heap, [0, start])
    trapvisited = defaultdict(int)




    for trap in traps:
        trapvisited[trap] = 0
    while heap:
        u = heapq.heappop(heap)
        if u[1] in traps :
            trapvisited[u[1]] += 1
            dist[u[1]] = u[0]
            for v in range(1,n+1) :
                for i in range(len(graph[u[1]][v])) :
                    graph[u[1]][v][i] = -graph[u[1]][v][i]
                for i in range(len(graph[v][u[1]])):
                    graph[v][u[1]][i] = -graph[v][u[1]][i]

        tmp = []
        traptmp = []
        for v in range(1,n+1,1) :
            for edge in graph[u[1]][v] :
                if edge > 0 :
                    newW = dist[u[1]] + edge
                    if dist[v] > newW and v not in traps  :
                        dist[v] = newW
                        tmp.append([newW, v])
                    elif dist[v] > newW and v in traps :
                        dist[v] = newW
                        tmp.append([newW, v])

                    elif v in traps and trapvisited[v] < 2 :
                        traptmp.append([newW, v])

        for t in tmp :
            heapq.heappush(heap,t)
        for t in traptmp:
            heapq.heappush(heap, t)

    return dist[end]


print(solution(3,1,3,[[1, 2, 2], [3, 2, 3]],[2]))
print(solution(4,1,4,[[1, 2, 1], [3, 2, 1], [2, 4, 1]],[2,3]))