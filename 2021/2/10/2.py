def solution(n, edge):
    answer = 0

    graph = [[] for _ in range(n+1)]

    for ed in edge :
        graph[ed[0]].append(ed[1])
        graph[ed[1]].append(ed[0])

    ans = [0 for _ in range(n+1)]
    queue = [1]

    while queue :
        front = queue.pop(0)

        for v in graph[front] :
            if ans[v] == 0 and v != 1:
                ans[v] = ans[front] + 1
                queue.append(v)


    maximum = 0
    for value in ans :
        if maximum < value :
            answer = 1
            maximum = value
        elif maximum == value :
            answer += 1


    return answer


print(solution(6,[[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]]))