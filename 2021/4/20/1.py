#프로그래머스 가장 큰 정사각형 찾기

def solution(board):
    answer = 0

    m = len(board)
    n = len(board[0])

    if m == 1 :
        if 1 in board[0] :
            return 1
        else :
            return 0



    for i in range(m-2,-1,-1):
        for j in range(n-1,-1,-1) :
            if j == n-1:
                continue
            if board[i][j] != 0 :
                board[i][j] += min(board[i+1][j],board[i][j+1],board[i+1][j+1])
                answer = max(board[i][j],answer)



    return answer*answer

print(solution([[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]))