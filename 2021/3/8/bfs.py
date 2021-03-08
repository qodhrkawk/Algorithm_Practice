#백준 2146 다리만들기
import copy

def makeDiff(maze,n,i,j,count) :
    dir = [[0, 1], [0, -1], [1, 0],[-1,0]]

    queue = [[i, j]]
    while queue :

        front = queue.pop(0)
        y = front[0]
        x = front[1]

        for d in dir:

            newY = y + d[0]
            newX = x + d[1]

            if newY < n and newY >= 0 and newX < n and newX >= 0:
                if maze[newY][newX] == 1 :
                    maze[newY][newX] = count
                    queue.append([newY, newX])




def bfs(maze,n,queue,count) :

    dir = [[0,1],[0,-1],[1,0]]


    ans = n*n


    while queue :


        front = queue.pop(0)
        y = front[0]
        x = front[1]

        for d in dir :

            newY = y+d[0]
            newX = x+d[1]



            if newY < n and newY >= 0 and newX < n and newX >= 0 and maze[newY][newX] != count:


                if maze[newY][newX] < 0 :
                    if maze[y][x] < 0 :
                        return 0

                    ans = min(ans,maze[y][x])
                elif maze[newY][newX] == 0 :
                    queue.append([newY,newX])
                    if maze[y][x] < 0 :
                        maze[newY][newX] = 1
                    else :

                        maze[newY][newX] = maze[y][x]+1


    return ans






def solution() :
    n = int(input())

    maze = []

    for _ in range(n) :
        line = list(map(int,input().split()))

        maze.append(line)
    count = 0
    for i in range(n) :
        for j in range(n) :
            if maze[i][j] == 1 :
                count -= 1
                maze[i][j] = count
                makeDiff(maze,n,i,j,count)


    ans = n*n


    for v in range(1,abs(count)+1) :
        val = -v
        q = []
        for i in range(n):
            for j in range(n):
                if maze[i][j] == val :
                    q.append([i,j])
        tmpMaze = copy.deepcopy(maze)

        ans = min(ans, bfs(tmpMaze, n, q,val))



    # for i in range(n) :
    #     for j in range(n) :
    #         if maze[i][j] == 0 :
    #             continue
    #         tmpMaze = copy.deepcopy(maze)
    #
    #
    #         ans = min(ans,bfs(tmpMaze,n,i,j))


    return ans




print(solution())