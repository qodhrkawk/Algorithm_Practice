#프로그래머스 - 가장 큰 수

def solution(numbers):
    answer = ''

    numberStrings = list(map(str,numbers))


    numberStrings = sorted(numberStrings,key = lambda  x : x*3,reverse= True)

    return str(int(''.join(numberStrings)))
