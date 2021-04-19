from _collections import deque


def solution(maps):
    n = len(maps)
    m = len(maps[0])

    dp = [[0 for _ in range(m)] for _ in range(n)]
    d = [[0,1],[0,-1],[1,0],[-1,0]]

    queue = deque()
    queue.append([0,0])
    dp[0][0] = 1

    while queue :
        front = queue.popleft()
        y,x = front[0],front[1]

        for i in range(4) :
            newY = y+d[i][0]
            newX = x+d[i][1]

            if 0<= newY < n and 0<= newX < m and maps[newY][newX] == 1 and dp[newY][newX] == 0 :
                dp[newY][newX] = dp[y][x] + 1
                queue.append([newY,newX])

    if dp[n-1][m-1] == 0 :
        return -1
    else :
        return dp[n-1][m-1]


print(solution([[1,0,1,1,1],[1,0,1,0,1],[1,0,1,1,1],[1,1,1,0,1],[0,0,0,0,1]]))