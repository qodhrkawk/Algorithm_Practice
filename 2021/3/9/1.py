#프로그래머스 순위


def solution(n, results):
    answer = 0

    INF = float('inf')

    graph = [[INF for _ in range(n+1)] for _ in range(n+1)]
    dist = [[INF for _ in range(n+1)] for _ in range(n+1)]



    for res in results :
        graph[res[0]][res[1]] = 1



    for i in range(n+1) :
        for j in range(n+1) :
            dist[i][j] = graph[i][j]
        dist[i][i] = 0


    for i in range(n+1) :
        for j in range(n+1) :
            for k in range(n+1) :
                if dist[i][j] > dist[i][k] + dist[k][j] :
                    dist[i][j] = dist[i][k] + dist[k][j]

    print(dist)


    return answer

print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))