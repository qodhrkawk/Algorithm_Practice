#백준 양 구출 작전
import sys
sys.setrecursionlimit(10**9)

def dfs(i,minus) :

    minuses[i] = minus
    if i != 1 and stats[i][0] == 'W' :
        minus -= stats[i][1]

    for v in graph[i] :
        dfs(v,minus)





n = int(input())

graph = [[] for _ in range(n+1)]
stats = [[] for _ in range(n+1)]


for i in range(n-1) :
    a,b,c = input().split()
    a,b,c = str(a),int(b),int(c)
    graph[c].append(i+2)
    stats[i+2] = [a,b]

minuses = [0 for _ in range(n+1)]
answer = 0

dfs(1,0)

for i in range(2,n+1) :

    if stats[i][0] == 'S' :
        if stats[i][1] + minuses[i] > 0 :
            answer += stats[i][1] + minuses[i]


print(answer)


