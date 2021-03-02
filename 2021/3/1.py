#백준 네트워크 연결

def find(parent,num) :
    if parent[num] == num :
        return num
    return find(parent,parent[num])


def union(parent,x,y) :

    x = find(parent,x)
    y = find(parent,y)

    if x == y :
        return
    else :
        if x < y :
            parent[y] = x
        else :
            parent[x] = y



def solution() :
    n = int(input())
    m = int(input())

    parent = [i for i in range(n+1)]

    costs = []
    answer = 0

    for i in range(m) :
        u,v,w = map(int,input().split())
        costs.append([u,v,w])

    costs = sorted(costs,key= lambda x: x[2])

    for edge in costs :
        if find(parent,edge[0]) != find(parent,edge[1]) :
            answer += edge[2]
            union(parent,edge[0],edge[1])

    return answer

print(solution())
