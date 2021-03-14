#백준 N-Queen

import sys

sys.setrecursionlimit(10**8)

def isValid(map,y,x) :
    diff = 0

    for i in range(y-1,-1,-1) :
        diff += 1
        if map[i][x] == 1 or (x-diff >= 0 and map[i][x-diff] == 1) or (x+diff < len(map) and map[i][x+diff] == 1) :
            return False


    return True





def dfs(map,depth) :
    if depth == len(map) :
        return 1
    answer = 0
    for i in range(len(map)) :
        if isValid(map,depth,i) :
            map[depth][i] = 1
            answer += dfs(map,depth+1)
            map[depth][i] = 0

    return answer




def solution() :

    n = int(input())

    map = [[0 for _ in range(n)] for _ in range(n)]

    answer = 0


    answer += dfs(map,0)






    return answer

print(solution())

