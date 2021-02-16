#프로그래머스 순위

def solution(n, results):
    answer = 0

    rank = [n//2 for _ in range(n+1)]
    counts = [0 for _ in range(n+1)]
    graph = [[]for _ in range(n+1)]

    certain = [0 for _ in range(n+1)]


    for res in results :
        counts[res[0]] += 1
        counts[res[1]] += 1
        rank[res[0]] -= 1
        rank[res[1]] += 1
        graph[res[0]].append(res[1])
        graph[res[1]].append(-res[0])

    queue = []
    for idx,c in enumerate(counts) :
        if c == n-1 :
            queue.append(idx)
            certain[rank[idx]] = 1

    while queue :
        front = queue.pop(0)

        for adj in graph[front] :
            if adj < 0 :
                tmp = 0
                idx = 0
                for i in range(1,rank[front]) :
                    if certain[i] == 0 :
                        tmp += 1
                        idx = i
                if tmp == 1 :
                    certain[adj] = 1
                    rank[adj] = idx
                    queue.append(adj)

            else :
                tmp = 0
                idx = 0
                for i in range(rank[front], n+1):
                    if certain[i] == 0:
                        tmp += 1
                        idx = i
                if tmp == 1:
                    certain[adj] = 1
                    rank[adj] = idx
                    queue.append(adj)


    for i in certain :
        if i == 1 :
            answer += 1

    return answer


print(solution(5,[[4, 3], [4, 2], [3, 2], [1, 2], [2, 5]]	))