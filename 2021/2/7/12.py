#프로그래머스 큰 수 만들기

def solution(number, k):

    stack = [number[0]]
    for i in number[1:] :
        while len(stack) > 0 and stack[-1] < i and k > 0 :
            k -= 1
            stack.pop()
        stack.append(i)

    if k > 0 :
        stack = stack[0:-k]

    return str(''.join(stack))
