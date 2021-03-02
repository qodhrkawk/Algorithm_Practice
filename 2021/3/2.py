
#백준 욕심쟁이 판다

from sys import setrecursionlimit
setrecursionlimit(10**9)

def dfs(n,graph,visited,y,x) :

    if visited[y][x] < 0 :
        visited[y][x] = 0

        dir = [[0,1],[0,-1],[1,0],[-1,0]]

        for d in dir :
            newY = y+d[0]
            newX = x+d[1]

            if newY >= 0 and newY < n and newX >= 0 and newX < n :
                if graph[y][x] < graph[newY][newX] :
                    visited[y][x] = max(visited[y][x],dfs(n,graph,visited,newY,newX))
        visited[y][x] += 1
    return visited[y][x]


def solution() :
    n = int(input())

    ans = 0

    visited = [[-1 for _ in range(n)] for _ in range(n)]
    graph = [list(map(int,input().split())) for _ in range(n)]

    for i in range(n) :
        for j in range(n) :
           ans = max(ans,dfs(n,graph,visited,i,j))


    return ans


print(solution())