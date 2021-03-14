#백준 구간 합 구하기 5

def solution() :

    n,m = map(int,input().split())

    arr = []

    for _ in range(n) :
        arr.append(list(map(int,input().split())))

    for i in range(n) :
        for j in range(n) :
            if j == 0 :
                continue
            arr[i][j] = arr[i][j] + arr[i][j-1]


    for _ in range(m) :
        x1,y1,x2,y2 = map(int,input().split())
        ans = 0
        for i in range(x1-1,x2) :
            if y1 == 1 :
                ans += arr[i][y2-1]
            else :
                ans += arr[i][y2-1]-arr[i][y1-2]

        print(ans)


solution()