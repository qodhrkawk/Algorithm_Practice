#프로그래머스 도둑질
import sys
sys.setrecursionlimit(10**7)


def dyamic(dp,n,lastAble,index) :

    if index >= n :
        return 0
    elif index == n-1 and lastAble == False :
        return 0
    elif  index == n-1 and lastAble == False :
        return dp[index]

    dp[index] =




def dfs(money,n,lastAble,index,sum) :
    if index == n :
        if lastAble :
            sum += money[n]
        return sum
    elif index > n :
        return sum

    else :
        sum += money[index]
        return max(dfs(money,n,lastAble,index+2,sum),dfs(money,n,lastAble,index+3,sum))

def solution(money):

    lastAble = money[:]
    lastDisAble = money[:]

    answer = max(dfs(money,len(money)-1,False,0,0),dfs(money,len(money)-1,True,1,0),dfs(money,len(money)-1,True,2,0))



    return answer


print(solution([1, 2, 3, 1]))