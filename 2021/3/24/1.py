# boj 달빛 여우


import heapq
import sys
sys.setrecursionlimit(10**9)




answer = 0

n,m = map(int,input().split())

graph = [[] for _ in range(n+1)]

for _ in range(m) :
    u,v,w = map(int,input().split())
    graph[u].append([v,w])
    graph[v].append([u,w])

dist = [float('inf') for _ in range(n+1)]
dist[1] = 0
paths = []
pathWeight = float('inf')

def dfs(u,goal,path,speed,val):
    global pathWeight
    if u == goal :
        if pathWeight > val :
            pathWeight = val
        paths.append(path)
    else :
        for v in graph[u] :
            if pathWeight > val + speed*v[1] :
                path.append(v[0])
                print(path)
                if speed == 0.5 :
                    dfs(v[0],goal,path,speed*4,val+speed*v[1])
                else :
                    dfs(v[0], goal, path, speed/4, val + speed *v[1])



def solution() :

    heap = []
    heapq.heappush(heap,[0,1])

    while heap:
        u = heapq.heappop(heap)

        for v in graph[u[1]]:
            if dist[v[0]] > dist[u[1]] + v[1] :
                dist[v[0]] = dist[u[1]] + v[1]
                heapq.heappush(heap,[dist[v[0]],v[0]])



    for i in range(2,n+1) :
        paths = []
        pathWeight = float('inf')
        dfs(1,i,[1],2,0)
        print(paths)
        print(pathWeight)



        print(dist)


    return answer



solution()