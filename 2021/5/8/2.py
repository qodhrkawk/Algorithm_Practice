

def bfs(oy,ox,place) :
    d = [[0,1],[0,-1],[1,0],[-1,0]]

    queue = [[oy,ox,0]]

    while queue :
        front = queue.pop()
        y,x = front[0],front[1]
        curWeight = front[2]

        for i in range(3) :
            newY = y + d[i][0]
            newX = x + d[i][1]

            if 0 <= newY < len(place) and 0 <= newX < len(place) and not(newY== oy and newX == ox):
                if place[newY][newX] == "P" :
                    # print(oy,ox,newY,newX,curWeight)
                    return False
                elif place[newY][newX] == "O" :
                    if curWeight < 1 :
                        queue.append([newY,newX,curWeight+1])

    return True


def check(place) :
    for i in range(5):
        for j in range(5):
            if place[i][j] == "P":
                if not bfs(i, j, place) :
                    return False
    return True

def solution(places):
    answer = []

    for place in places :
        if check(place) :
            answer.append(1)
        else :
            answer.append(0)




    return answer


print(solution([["POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"], ["POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"], ["PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"], ["OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"], ["PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"]]))