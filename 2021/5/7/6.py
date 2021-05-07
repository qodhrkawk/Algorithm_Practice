# 프로그래머스 최적의 행렬 곱셈

INF = float('inf')
dp = []
def solve(arr,i,j) :

    if dp[i][j] != INF :
        return dp[i][j]
    if i == j :
        dp[i][j] = 0
    else :
        for k in range(i,j) :
            tmp = solve(arr,i,k) + solve(arr,k+1,j) + arr[i][0]*arr[k][1]*arr[j][1]

            if tmp < dp[i][j] :
                dp[i][j] = tmp
    return dp[i][j]

def solution(matrix_sizes):

    global dp

    n = len(matrix_sizes)

    dp = [[INF for _ in range(n)] for _ in range(n)]

    return solve(matrix_sizes,0,n-1)

print(solution([[5,3],[3,10],[10,6]]))
