#프로그래머스 삼각 달팽이

def solution(n):
    answer = []

    arr = [[] for _ in range(n+1)]
    for i in range(len(arr)) :
        arr[i] = [0 for _ in range(i)]


    # 0 : 아래로 1 : 오른쪽으로 2 : 위로
    state = 0
    index = (1,0)
    maximum = int(n*(n+1)/2)


    for i in range(1,maximum+1,1) :
        arr[index[0]][index[1]] = i
        if state == 0 :

            if index[0] < n and arr[index[0]+1][index[1]] == 0 :
                index = (index[0]+1,index[1])

            else :
                state = 1
                index = (index[0], index[1]+1)

        elif state == 1 :
            if index[1]+1 < index[0] and arr[index[0]][index[1]+1] == 0 :
                index = (index[0], index[1]+1)
            else :
                state = 2
                index = (index[0]-1, index[1]-1)

        else :
            if index[0] > 1 and arr[index[0]-1][index[1]-1] == 0 :
                index = (index[0]-1,index[1]-1)

            else :
                state = 0
                index = (index[0]+1, index[1])

    for i in range(1,len(arr)) :
        for j in range(len(arr[i])) :
            answer.append(arr[i][j])


    return answer
