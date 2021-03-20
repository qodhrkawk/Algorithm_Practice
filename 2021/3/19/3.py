#프로그래머스 프렌즈 4블록


def check(i,j,m,n,myMap) :

    if i+1 < m and j+1 < n :
        if myMap[i][j] == myMap[i+1][j] == myMap[i+1][j+1] == myMap[i][j+1] and myMap[i][j] != 0:
            return True


    return False




def solution(m, n, board):
    answer = 0

    myMap = [['' for _ in range(n)] for _ in range(m)]

    flag = True

    for i in range(m) :
        for j in range(n) :
            myMap[i][j] = board[-i-1][j]
    while flag :
        flag = False
        points = []
        for i in range(m):
            for j in range(n) :
                if check(i,j,m,n,myMap) :
                    points.append([i,j])
                    flag = True

        for p in points :
            myMap[p[0]][p[1]] = myMap[p[0]+1][p[1]] = myMap[p[0]][p[1]+1] = myMap[p[0]+1][p[1]+1] = 0


        counts = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m-1,0,-1) :
            for j in range(n) :
                for k in range(i-1,-1,-1) :
                    if myMap[k][j] == 0 :
                        counts[i][j] += 1

        for i in range(m) :
            for j in range(n) :
                if counts[i][j] > 0 :
                    myMap[i][j],myMap[i-counts[i][j]][j] = 0,myMap[i][j]




    for i in range(m) :
        for j in range(n) :
            if myMap[i][j] == 0 :
                answer += 1



    return answer


print(solution(4,5,["CCBDE", "AAADE", "AAABF", "CCBBF"]))