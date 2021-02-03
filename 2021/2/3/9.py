#프로그래머스 K번째수

def solution(array, commands):
    answer = []
    print(len(commands))
    for i in range(len(commands)) :
        tmpArr = array[commands[i][0]-1:commands[i][1]]
        tmpArr.sort()
        answer.append(tmpArr[commands[i][2]-1])



    return answer