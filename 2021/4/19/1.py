from _collections import deque


def solution(bridge_length, weight, truck_weights):

    queue = deque()
    nowWeight = truck_weights[0]
    time = 1

    queue.append([truck_weights[0],1])
    truckIdx = 1

    while truckIdx < len(truck_weights) :

        # print(queue,truckIdx)
        time += 1

        if truckIdx < len(truck_weights) :

            if nowWeight + truck_weights[truckIdx] <= weight :
                nowWeight += truck_weights[truckIdx]
                queue.append([truck_weights[truckIdx],time])
                truckIdx += 1

        if len(queue) != 0 and time-queue[0][1] == bridge_length-1 :
            nowWeight -= queue.popleft()[0]

    while queue :
        time += 1
        # print(queue,time)
        if time-queue[0][1] == bridge_length-1 :
            nowWeight -= queue.popleft()[0]






    return time+1

print(solution(2,10,[7,4,5,6]))
print(solution(100,100,[10]))
print(solution())