#프로그래머스 섬 연결하기


def find(parent,num) :
    if parent[num] == num :
        return num
    else :
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

def solution(n, costs):
    answer = 0

    parent = [i for i in range(n)]

    costs = sorted(costs,key= lambda x: x[2])

    for edge in costs :
        if find(parent,edge[0]) != find(parent,edge[1]) :
            answer += edge[2]
            print((edge[0],edge[1]))
            union(parent,edge[0],edge[1])




    return answer


# print(solution(4,[[0,1,1],[0,2,2],[1,2,5],[1,3,1],[2,3,8]]))