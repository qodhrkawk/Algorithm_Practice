#백준 알파벳

from _collections import defaultdict
from _collections import deque



def dfs(depth,y,x) :
    d = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    global  ans
    ans = max(ans,depth)

    for i in range(4):
        newY = y + d[i][0]
        newX = x + d[i][1]

        if 0 <= newY < r and 0 <= newX < c and history[arr[newY][newX]] == 0:
            history[arr[newY][newX]] = 1
            dfs(depth+1,newY,newX)
            history[arr[newY][newX]] = 0


r,c = map(int,input().split())
arr = [list(map(lambda x: ord(x)-65,input())) for _ in range(r)]
ans = 1

history = [0 for _ in range(26)]
history[arr[0][0]] = 1



dfs(1,0,0)
print(ans)

