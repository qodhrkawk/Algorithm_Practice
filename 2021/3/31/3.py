#프로그래머스 경주로 건설

import sys
sys.setrecursionlimit(10**9)

answer = float('inf')

def bfs(board,n,dp,direction) :
    d = [[0, 1], [0, -1], [1, 0], [-1,0]]


    queue = [[0,0]]

    while queue :

        front = queue.pop(0)
        x,y = front[0],front[1]


        for i in range(4):
            newY = y + d[i][0]
            newX = x + d[i][1]

            if 0 <= newY < n and 0 <= newX < n and board[newY][newX] == 0 :
                adder = 0
                if y == 0 and x == 0 :
                    adder = 1

                elif direction[y][x] == i :
                    adder = 1
                else :
                    adder = 6
                if dp[newY][newX] > adder + dp[y][x] :
                    dp[newY][newX] = adder + dp[y][x]
                    direction[newY][newX] = i

                    queue.append([newY,newX])




def solution(board):
    global answer

    n = len(board)

    # answer = 6*n*n
    INF = float('inf')
    dp = [[INF for _ in range(n)] for _ in range(n)]
    direction = [[-1 for _ in range(n)] for _ in range(n)]

    dp[0][0] = 0
    bfs(board,n,dp,direction)
    print(dp)


    return dp[n-1][n-1]*100








print(solution([[0,0,0],[0,0,0],[0,0,0]]))

print(solution([[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0],[0,0,0,0,1,0,0,0],[0,0,0,1,0,0,0,1],[0,0,1,0,0,0,1,0],[0,1,0,0,0,1,0,0],[1,0,0,0,0,0,0,0]]))
print(solution([[0,0,1,0],[0,0,0,0],[0,1,0,1],[1,0,0,0]]))


print(solution([[0, 0, 1, 0, 1, 1, 0, 0, 0, 0],[0, 0, 0, 0, 1, 0, 1, 1, 0, 1],[1, 0, 0, 0, 0, 1, 1, 0, 1, 0],[0, 0, 0, 0, 0, 0, 1, 0, 0, 0],[0, 0, 0, 0, 1, 0, 1, 0, 1, 1],[0, 0, 1, 0, 1, 1, 0, 1, 0, 1],[0, 1, 0, 0, 1, 0, 0, 0, 1, 0],[1, 0, 0, 1, 0, 0, 0, 0, 0, 0],[0, 0, 0, 0, 0, 1, 0, 1, 0, 0],[1, 0, 0, 0, 0, 0, 0, 0, 1, 0]]))