
def solution(n, s, a, b, fares):

    INF = float('inf')

    graph = [[INF for _ in range(n+1)] for _ in range(n+1)]

    dist = [[INF for _ in range(n+1)] for _ in range(n+1)]

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
                if dist[i][j] > dist[i][k] + dist[j][k] :
                    dist[i][j] = dist[i][k] + dist[j][k]

    answer = dist[s][a]+dist[s][b]
    for k in range(n+1) :
        if k == s :
            continue
        answer = min(answer,dist[s][k]+dist[k][a]+dist[k][b])


    return answer