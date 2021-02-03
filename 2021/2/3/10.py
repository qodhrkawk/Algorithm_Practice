#프로그래머스 서울에서 김서방 찾기

def solution(seoul):
    answer = ''

    for i in range(len(seoul)):
        if seoul[i] == "Kim" :
            answer = "김서방은 "+str(i)+"에 있다"
            break
    return answer