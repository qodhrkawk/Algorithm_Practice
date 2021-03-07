#백준 숨바꼭질

import heapq


def solution() :
    n,k = map(int,input().split())

    queue = [[0,n]]
    visited = [False]*100001
    count = 0
    while queue :
        front = queue.pop(0)
        # print(front)

        if not visited[front[1]] :

            visited[front[1]] = True
            count = front[0]

            if front[1] == k :
                return count

            count += 1

            if front[1]+1 <= 100000 :
                heapq.heappush(queue, [count, front[1] + 1])
            if front[1]-1 >= 0 :
                heapq.heappush(queue, [count, front[1] - 1])
            if front[1]*2 <= 100000 :
                heapq.heappush(queue, [count, front[1] * 2])

    return count





print(solution())