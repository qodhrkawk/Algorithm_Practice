#백준 구간 합 구하기

import math


def seg(arr,tree,node,start,end) :
    if start == end :
        tree[node] = arr[start]
        return tree[node]
    else :
        tree[node] = seg(arr,tree,node*2,start,(start+end)//2) +  seg(arr,tree,node*2+1,(start+end)//2+1,end)
        return tree[node]


def segSum(tree,node,start,end,left,right) :
    if left > end or right < start :
        return 0
    if left <= start and end <= right :
        return tree[node]

    return segSum(tree,node*2,start,(start+end)//2,left,right) + segSum(tree,node*2+1,(start+end)//2+1,end,left,right)


def update(tree,node,start,end,index,diff) :


    if index < start or index > end :
        return
    tree[node] = tree[node] + diff

    if start != end :
        update(tree,node*2,start,(start+end)//2,index,diff)
        update(tree, node*2+1, (start+end)//2+1, end, index, diff)




def solution() :
    n,m,k = map(int,input().split())

    arr = []

    h = math.ceil(math.log2(n))

    tree_size = 1 << (h+1)


    for _ in range(n) :
        arr.append(int(input()))

    tree = [0 for _ in range(tree_size)]

    seg(arr,tree,1,0,n-1)


    for _ in range(m+k) :
        a,b,c = map(int,input().split())

        if a == 2 :
            print(segSum(tree,1,0,n-1,b-1,c-1))

        else :
            diff = c-arr[b-1]
            arr[b-1] = c
            update(tree,1,0,n-1,b-1,diff)




solution()