def rotate(key) :

    return list(zip(*key[::-1]))

def check(map,m,n) :
    for i in range(n):
        for j in range(n) :
            if map[m+i][m+j] != 1 :
                return False
    return True

def insert(y,x,m,map,key) :
    for i in range(m):
        for j in range(m) :
            map[i+y][j+x] += key[i][j]
def undo(y,x,m,map,key) :
    for i in range(m):
        for j in range(m):
            map[i+y][j+x] -= key[i][j]


def solution(key, lock):
    answer = False
    n = len(lock)
    m = len(key)


    map = [[0] * (m*2 + n) for _ in range(m*2 + n)]

    for i in range(n):
        for j in range(n) :
            map[m+i][m+j] = lock[i][j]

    for num in range(4) :
        key = rotate(key)

        for y in range(1,m+n):
            for x in range(1,m+n) :
                insert(y,x,m,map,key)

                if check(map,m,n) :
                    return  True

                undo(y,x,m,map,key)







    return answer


print(solution(	[[0, 0, 0], [1, 0, 0], [0, 1, 1]], [[1, 1, 1], [1, 1, 0], [1, 0, 1]]))