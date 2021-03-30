#프로그래머스 징검다리

def solution(distance, rocks, n):
    answer = 0

    rocks = sorted(rocks)
    tmp = [rocks[0]]
    for i in range(1,len(rocks)) :
        tmp.append(rocks[i]-rocks[i-1])
    tmp.append(distance-rocks[len(rocks)-1])




    return answer