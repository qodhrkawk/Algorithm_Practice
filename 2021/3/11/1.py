#백준 피자굽기 1756


def binarySearch(left,right,arr,val) :

    for i in range(left,right+1) :
        if arr[i] < val :
            return i-1

    return right-1




def solution() :

    d,n = map(int,input().split())


    shape = list(map(int,input().split()))
    inputs = list(map(int,input().split()))



    left,right = 0,len(shape)-1




    for idx,num in enumerate(inputs) :

        right = binarySearch(left,right,shape,num)
        if right < 0 and idx < n-1:
            print(0)
            return
     


    print(right+1)


solution()