import heapq

def solution(food_times, k):

    infos = []


    for idx,f in enumerate(food_times) :
       heapq.heappush(infos,[f,idx+1])




    now = heapq.heappop(infos)
    prev = [0,0]

    while (now[0]-prev[0])*(len(infos)+1) <= k :
        k -= (now[0]-prev[0])*(len(infos)+1)
        prev = now
        while now[0] == prev[0] :
            now = heapq.heappop(infos)
            if len(infos) == 0  :
                if k == 1 :
                    return now[1]
                else :
                    return -1

    heapq.heappush(infos,now)
    if len(infos) == 0 :
        return -1

    infos = sorted(infos,key= lambda x: x[1])

    return infos[k%len(infos)][1]



print(solution([3,1,2],5))

