#백준 로봇 조종하기

import sys
sys.setrecursionlimit(10**9)

def dfs(y,x) :


    if y == n-1 and x == m-1 :
        dp[y][x] = arr[y][x]
        return dp[y][x]

    for i in range(3) :
        newY = y + d[i][0]
        newX = x + d[i][1]

        if 0 <= newY < n and 0 <= newX < m and not visited[newY][newX]:
            # print(y,x,newY,newX)
            visited[newY][newX] = True
            if dp[newY][newX] == -INF :
                dp[y][x] = max(dp[y][x],dfs(newY,newX))

            else :
                dp[y][x] = max(dp[y][x],dp[newY][newX])
            visited[newY][newX] = False


    dp[y][x] += arr[y][x]
    return dp[y][x]



n,m = map(int,input().split())
INF = float('inf')

visited = [[False for _ in range(m)] for _ in range(n)]
d = [[0,1],[0,-1],[1,0]]

dp = [[-INF for _ in range(m)] for _ in range(n)]

arr = []
for _ in range(n) :
    arr.append(list(map(int,input().split())))

# print(arr)
visited[0][0] = True
dfs(0,0)
# print(dp)

print(dp[0][0])
