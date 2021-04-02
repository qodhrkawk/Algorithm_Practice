#프로그래머스 징검다리

import copy
def check(tmp,limit,n) :

    arr = copy.deepcopy(tmp)
    count = 0
    idx = 0
    while idx < len(arr) :
        if arr[idx] < limit :
            if idx+1 < len(arr) :
                arr[idx+1] += arr[idx]
                count += 1
            else :
                return  False


        if count > n :
            return False
        idx += 1



    return True


def solution(distance, rocks, n):
    answer = 0

    rocks = sorted(rocks)
    tmp = [rocks[0]]
    for i in range(1,len(rocks)) :
        tmp.append(rocks[i]-rocks[i-1])
    tmp.append(distance-rocks[len(rocks)-1])


    left,right = 0,distance

    while left<=right:
        mid = (left+right)//2

        if not check(tmp,mid,n) :
            right = mid-1
        else :
            answer = mid
            left = mid+1



    return answer

print(solution(25,[2,14,11,21,17],2))