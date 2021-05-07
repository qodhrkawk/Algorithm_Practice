
def find(parent,x) :
    if parent[x] == x :
        return x
    return find(parent,parent[x])


def union(parent,x,y) :
    x,y = find(parent,x),find(parent,y)
    if x == y :
        return
    if x < y :
        parent[y] = x
    else :
        parent[x] = y


def solution(k, room_number):
    answer = []

    dp = [True for _ in range(k+1)]
    parent = [i for i in range(k+1)]




    for num in room_number :
        if dp[num] :
            dp[num] = False
            if dp[num-1] == False :
                union(parent,num,num-1)
            answer.append(num)
        else :



            for i in range(num+1,k+1) :
                if dp[i] :
                    dp[i] = False
                    answer.append(i)
                    break
    return answer