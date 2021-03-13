#백준 피자굽기 1756


def binarySearch(left,right,arr,val) :

    for i in range(right,left-1,-1) :
        if arr[i] >= val :
            return i
    return -1

    #
    # for i in range(left,right+1) :
    #     if arr[i] < val :
    #         return i-1
    #
    # return right-1




def solution() :

    d,n = map(int,input().split())


    shape = list(map(int,input().split()))
    inputs = list(map(int,input().split()))

    minimum = 300000

    for idx,num in enumerate(shape) :
        if num < minimum :
            minimum = num

        else :
            shape[idx] = minimum

    # print(shape)




    left,right = 0,len(shape)-1




    for idx,num in enumerate(inputs) :

        right = binarySearch(left,right,shape,num)
        print(right)
        if right == - 1:
            print(0)
            return
        if idx < n-1 :
            right = right-1



        # right = binarySearch(left,right,shape,num)
        # if right < 0 and idx < n-1:
        #     print(0)
        #     return
     


    print(right+1)


solution()