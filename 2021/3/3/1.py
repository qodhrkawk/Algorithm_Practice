#백준 파일 합치기


def solution() :
    t = int(input())

    for _ in range(t) :

        k = int(input())
        arr = list(map(int,input().split()))

        arr = sorted(arr)
        ans = 0
        while arr :
            print(arr)
            if len(arr)%2 == 0 :
                n = len(arr)
                tmp = []
                for i in range(n//2) :
                    left = arr.pop(0)
                    right = arr.pop(-1)

                    ans += left+right
                    tmp.append(left+right)
                arr = tmp


            else :
                if len(arr) == 1 :
                    print(ans)
                    break
                n = len(arr)
                tmp = [arr.pop(-1)]
                for i in range(n//2) :
                    left = arr.pop(0)
                    right = arr.pop(-1)
                    tmp.append(left+right)
                    ans += left + right
                arr = tmp
            arr = sorted(arr)









solution()