#boj 1로 만들기

from _collections import deque

def solution() :
    n = int(input())


    queue = deque()

    queue.append(n)



    if n == 1 :
        return 0

    dp = [[],[n]]
    ans = 2

    while True :

        tmp = []
        for num in dp[ans-1] :
            if num == 1 :
                return ans-2
            if num % 2 == 0 :
                tmp.append(num//2)
            if num%3 == 0 :
                tmp.append(num//3)
            tmp.append(num-1)
        ans += 1
        dp.append(tmp)





print(solution())


