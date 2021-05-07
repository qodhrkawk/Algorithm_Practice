
import sys
sys.setrecursionlimit(10**9)

INF = float('inf')


def solution(strs, t):

    n = len(t)
    dist = [[INF for _ in range(n)] for _ in range(n)]

    for i in range(n) :
        for j in range(n) :
            if t[i:j+1] in strs :
                dist[i][j] = 1


    for k in range(n-1) :
        for i in range(n) :
            for j in range(n) :
                if dist[i][j] > dist[i][k] + dist[k+1][j] :
                    dist[i][j] = dist[i][k] + dist[k+1][j]

    if dist[0][n-1] == INF :
        return -1

    return dist[0][n-1]


print(solution(["ba","na","n","a"],"banana"))
print(solution(["app","ap","p","l","e","ple","pp"],"apple"))