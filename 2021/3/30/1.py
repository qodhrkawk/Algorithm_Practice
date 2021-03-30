#프로그래머스 경주로 건설

import sys
sys.setrecursionlimit(10**9)

answer = float('inf')

def dfs(board,n,visited,y,x,lastDir,res,dp) :
    global answer

    if res > answer :
        return

    if dp[y][x] < res :
        return
    else :
        dp[y][x] = res

    if y == n-1 and x == n-1 :
        return

    d = [[0,1],[0,-1],[1,0],[0,1]]

    for i in range(4) :
        newY = y + d[i][0]
        newX = x + d[i][1]

        if 0 <= newY < n and 0 <= newX < n and board[newY][newX] == 0 and not visited[newY][newX] :
            visited[newY][newX] = True
            if y == 0 and x == 0 :
                dfs(board, n, visited, newY, newX, i, res + 1,dp)
            elif lastDir != i :
                dfs(board,n,visited,newY,newX,i,res+6,dp)
            else:
                dfs(board, n, visited, newY, newX, i, res + 1,dp)
            visited[newY][newX] = False








def solution(board):
    global answer

    n = len(board)

    # answer = 6*n*n
    INF = float('inf')
    dp = [[INF for _ in range(n)] for _ in range(n)]
    visited = [[False for _ in range(n)] for _ in range(n)]

    dfs(board,n,visited,0,0,0,0,dp)
    print(dp)

    return dp[n-1][n-1]*100














print(solution([[0, 0, 1, 0, 1, 1, 0, 0, 0, 0],[0, 0, 0, 0, 1, 0, 1, 1, 0, 1],[1, 0, 0, 0, 0, 1, 1, 0, 1, 0],[0, 0, 0, 0, 0, 0, 1, 0, 0, 0],[0, 0, 0, 0, 1, 0, 1, 0, 1, 1],[0, 0, 1, 0, 1, 1, 0, 1, 0, 1],[0, 1, 0, 0, 1, 0, 0, 0, 1, 0],[1, 0, 0, 1, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 1, 0, 1, 0, 0],[1, 0, 0, 0, 0, 0, 0, 0, 1, 0]]))