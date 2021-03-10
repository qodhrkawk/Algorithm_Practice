#프로그래머스 순위


def solution(n, results):
    answer = 0

    graph = [[0 for _ in range(n+1)] for _ in range(n+1)]
    dist = [[0 for _ in range(n+1)] for _ in range(n+1)]



    for res in results :
        graph[res[0]][res[1]] = 1
        graph[res[1]][res[0]] = -1



    for i in range(n+1) :
        for j in range(n+1) :
            dist[i][j] = graph[i][j]



    for k in range(n+1) :
        for i in range(n+1) :
            for j in range(n+1) :
                if dist[i][k] == 1 and dist[k][j] == 1 :
                    dist[i][j] = 1
                elif dist[i][k] == -1 and dist[k][j] == -1 :
                    dist[i][j] = -1
        # print(dist)


    for i in range(n+1) :
        flag = True
        for j in range(1,n+1) :
            if dist[i][j] == 0 and i != j :
                flag = False
                break

        if flag :
            answer += 1

    # print(dist)


    return answer

print(solution(5, [[1, 4], [4, 2], [2, 5], [5, 3]]))
print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]))