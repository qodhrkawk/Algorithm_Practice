#백준 숫자카드

def solution() :
    m = int(input())

    arr = list(map(int,input().split()))

    arr = sorted(arr)

    k = int(input())

    ans = []


    findArr = list(map(int,input().split()))


    for target in findArr :

        left , right = 0,len(arr)-1
        flag = False
        while left<= right :
            mid = (left+right)//2
            if arr[mid] == target :
                flag = True
                ans.append(1)
                break

            elif arr[mid] > target :
                right = mid-1
            else :
                left = mid+1

        if not flag :
            ans.append(0)

    for a in ans :
        print(a,end= " ")






solution()