#백준 줄 세우기

from _collections import defaultdict


def solution() :
    n,m = map(int,input().split())

    rank = [[0,i] for i in range(n+1)]
    graph = [[] for i in range(n+1)]


    for _ in range(m):
        a,b = map(int,input().split())
        rank[b][0] += 1
        graph[a].append(b)

    queue = []

    for r in rank :
        if r[1] == 0 :
            continue
        if r[0] == 0 :
            queue.append(r)


    while queue :
        front = queue.pop(0)
        print(front[1],end= " ")

        for adj in graph[front[1]] :
            rank[adj][0] -= 1
            if rank[adj][0] == 0 :
                queue.append(rank[adj])





solution()