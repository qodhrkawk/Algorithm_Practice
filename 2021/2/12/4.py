#프로그래머스 숫자 게임


def solution(A, B):
    answer = 0
    A = sorted(A)
    B= sorted(B)

    for idx,num in enumerate(B):
        if A[0] < num :
            answer += 1
            A.pop(0)
        else :
            A.pop(-1)


    return answer


