#프로그래머스 타겟 넘버

answer = 0

def dfs(numbers,result,depth,size,target) :
    global  answer

    if depth >= size :
        if result == target :
            answer += 1
    else :
        dfs(numbers,result+numbers[depth],depth+1,size,target)
        dfs(numbers,result-numbers[depth],depth+1,size,target)

def solution(numbers, target):


    dfs(numbers,0,0,len(numbers),target)


    return answer