
#백준 파일 합치기





def solution():

    t = int(input())


    for _ in range(t) :
        k = int(input())

        inp = list(map(int,input().split()))

        arr = [0 for _ in range(k+1)]
        dp = [[0 for _ in range(k+1)] for _ in range(k+1)]

        sums = [0 for _ in range(k+1)]

        for i in range(k+1) :
            arr[i] = inp[i-1]


        for i in range(1,len(arr)) :
            sums[i] = sums[i-1] + arr[i]





        for d in range(1,k) :
            for i in range(1,k+1) :
                if i + d > k :
                    break
                j = i + d
                dp[i][j] = float('inf')
                for x in range(i,j) :
                    dp[i][j] = min(dp[i][x]+dp[x+1][j]+sums[j]-sums[i-1],dp[i][j])

        print(dp[1][k])








solution()