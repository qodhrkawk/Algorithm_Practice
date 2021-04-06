import  sys
sys.setrecursionlimit(10**9)


def dfs(depth,n,count) :
    if depth == 2*n :
        if count == 0 :
            return 1
        else :
            return 0
    ans = 0
    if count > 0 :
        ans += dfs(depth+1,n,count-1)
        ans += dfs(depth+1,n,count+1)
    else :
        ans += dfs(depth+1,n,count+1)

    return ans

def solution(n):

    return dfs(0,n,0)

print(solution(14))