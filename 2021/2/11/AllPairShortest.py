# 프로그래머스 합승 택시 요금

import sys

INF = sys.maxsize


def solution(n, s, a, b, fares):
    answer = 0

    dist = [[INF]*(n+1) for i in range(n+1)]
    graph = [[INF for _ in range(n+1)] for _ in range(n + 1)]

    for fare in fares :
        graph[fare[0]][fare[1]] = fare[2]
        graph[fare[1]][fare[0]] = fare[2]


    for i in range(n+1) :
        for j in range(n+1) :
            dist[i][j] = graph[i][j]
        dist[i][i] = 0

    for k in range(n+1) :
        for i in range(n+1) :
            for j in range(n+1) :
                if dist[i][j] > dist[i][k] + dist[k][j] :
                    dist[i][j] = dist[i][k] + dist[k][j]


    candidate = []
    candidate.append(dist[s][a]+dist[s][b])

    for i in range(n+1) :
        if i == s:
            continue
        candidate.append(dist[s][i]+dist[i][a]+dist[i][b])

    answer = min(candidate)


    return answer


print(solution(6, 4, 6, 2,
               [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22],
                [1, 6, 25]]))