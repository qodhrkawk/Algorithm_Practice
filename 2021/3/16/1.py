# 백준 사회망 서비스
import sys

sys.setrecursionlimit(10**9)


def dfs(cur) :

    visited[cur] = True

    dp[cur][0] = 1
    dp[cur][1] = 0

    for v in tree[cur] :
        if not visited[v] :
            dfs(v)
            dp[cur][0] += dp[v][1]
            dp[cur][1] += max(dp[v][0],dp[v][1])




n = int(input())

tree = [[] for _ in range(n+1)]
dp = [[0,0] for _ in range(n+1)]
visited = [False for _ in range(n+1)]

for _ in range(n-1):
    u,v = map(int,input().split())
    tree[u].append(v)
    tree[v].append(u)

dfs(1)

print(n-max(dp[1]))



