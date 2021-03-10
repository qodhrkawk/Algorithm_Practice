#프로그래머스 징검다리 건너기


def check(stones,k,val) :

    cnt = 0

    for st in stones :

        if st < val :
            cnt += 1
            if cnt >= k :
                return False
        else :
            cnt = 0



    return True


def solution(stones, k):

    answer = 0
    if len(stones) == k :
        return min(stones)


    right = max(stones)
    left = min(stones)






    while left <= right :
        mid = (right + left) // 2

        if check(stones,k,mid) :
            if mid > answer:
                answer = mid
            left = mid+1
        else :
            right = mid-1









    return answer




print(solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1],3))