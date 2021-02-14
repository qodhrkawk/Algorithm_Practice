#프로그래머스 입국심사


def solution(n, times):
    answer = 0

    left,right = 1, max(times)*n

    while left <= right :
        mid = (right+left) // 2
        tmp = n
        for t in times :
            tmp -= mid//t
            if tmp <= 0 :
                answer = mid
                right = mid - 1
                break
        if tmp > 0 :
            left = mid+1

    return answer






print(solution(6,[7,10]))