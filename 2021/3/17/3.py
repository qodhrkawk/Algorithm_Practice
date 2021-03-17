#백준 피자굽기 1756


def binarySearch(left ,right ,arr ,val) :

    for i in range(right ,left-1 ,-1) :
        if arr[i] >= val :
            return i
    return -1


def solution() :

    d ,n = map(int ,input().split())


    shape = list(map(int ,input().split()))
    inputs = list(map(int ,input().split()))


    for idx in range(1,d) :
        shape[idx] = min(shape[idx],shape[idx-1])


    left ,right = 0 ,len(shape)-1

    for idx ,num in enumerate(inputs) :

        right = binarySearch(left ,right ,shape ,num)
        if right == - 1:
            print(0)
            return
        if idx < n- 1:
            right = right - 1


    print(right + 1)


solution()