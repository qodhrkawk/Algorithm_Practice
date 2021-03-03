#백준 파일 합치기
import heapq

def solution() :
    t = int(input())

    for _ in range(t) :

        k = int(input())
        arr = list(map(int,input().split()))

        arr = sorted(arr)

        i,j = 0,k-1
        ans = 0
        tmpArr = []
        while i < j :
            left = arr.pop()
            right = arr.pop(-1)

            sum = left+right

            ans += sum







solution()