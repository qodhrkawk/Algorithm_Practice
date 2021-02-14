#프로그래머스 이중우선순위큐

import heapq

def solution(operations):
    answer = []

    queue = []
    for op in operations :
        words = op.split()
        if words[0] == "I" :
            heapq.heappush(queue,int(words[1]))
        else :
            if len(queue) == 0 :
                continue

            if words[1] == '-1' :
                heapq.heappop(queue)
            else:
                queue.pop(-1)
    if queue :
        answer = [max(queue),min(queue)]
    else :
        answer = [0,0]



    return answer



print(solution(["I 16","D 1"]))