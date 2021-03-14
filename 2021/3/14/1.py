#백준 차이를 최대로


from itertools import permutations

def solution() :
    n = int(input())

    arr = list(map(int,input().split()))


    perm = list(permutations(arr,len(arr)))

    answer = 0
    for p in perm :
        tmp = 0
        for i in range(len(p)-1) :
            tmp += abs(p[i]-p[i+1])
        answer = max(tmp,answer)

    return answer

print(solution())
