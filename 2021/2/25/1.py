import heapq

def solution(food_times, k):

    infos = []


    for idx,f in enumerate(food_times) :
       infos.append([f,idx+1])


    infos = sorted(infos)

    now = infos[0][0]
    prev = 0

    while (now-prev)*len(infos) <= k :
        k -= (now-prev)*len(infos)
        while infos[0][0] == now :
            infos.pop(0)
            if len(infos) == 0 :
                return -1
        prev = now
        now = infos[0][0]
    if len(infos) == 0 :
        return -1

    infos = sorted(infos,key= lambda x: x[1])

    return infos[k%len(infos)][1]



print(solution([3,1,2],5))

