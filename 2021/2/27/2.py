
from itertools import permutations


def solution() :
    n, m = map(int,input().split())


    mList = [i for i in range(1,n+1)]

    comb = list(permutations(mList,m))

    for c in comb:
        for e in c :
            print(e,end= ' ')
        print()



solution()

