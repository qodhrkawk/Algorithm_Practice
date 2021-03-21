def solution(enter, leave):


    n = len(enter)
    answer = [0 for _ in range(n)]
    dpEnter = [0 for _ in range(n+1)]
    dpLeave = [0 for _ in range(n+1)]

    for idx,e in enumerate(enter) :
        dpEnter[e] = idx

    for idx, l in enumerate(leave):
        dpLeave[l] = idx




    graph = [[0 for _ in range(n+1)] for _ in range(n+1)]

    for idx,e in enumerate(enter) :
        for j in range(idx+1,len(enter)) :
            if dpLeave[enter[j]] < dpLeave[e] :
                graph[enter[j]][e] = 1
                graph[e][enter[j]] = 1

    for k in range(1,n+1) :
        for i in range(1,n+1) :
            for j in range(1,n+1) :
                if graph[i][k] > 0 and graph[k][j] > 0 :
                    if i != j and dpEnter[k] > dpEnter[i] and dpLeave[k] < dpLeave[j]:
                        graph[i][j] = 1



    for i in range(1,n+1) :
        for v in graph[i] :
            if v > 0 :
                answer[i-1] += 1


    return answer