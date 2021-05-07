#프로그래머스 수식 최대화
from itertools import permutations
import re

def solution(expression):
    answer = 0

    operator = []

    if "+" in expression :
        operator.append("+")
    if "-" in expression :
        operator.append("-")
    if "*" in expression :
        operator.append("*")

    perm = list(permutations(operator,3))

    num = ""
    nums = []
    ops = []
    for i in range(len(expression)) :
        if expression[i].isdigit() :
            num += expression[i]
        else :
            nums.append(int(num))
            num = ""
            ops.append(expression[i])
    nums.append(int(num))

    print(nums)
    print(ops)


    for p in perm :
        numStack = []
        opStack = []
        for i in range(3) :
            op = p[i]
            for idx,o in enumerate(ops) :
                if o == op :
                    numStack.append([idx,idx+1])
                    opStack.append(o)
        midStack = []
        for idx,os in enumerate(opStack) :
            if os == "+" :
                midStack.append(nums(numStack[idx][0])+numStack[idx][1])
            elif os == "-" :
                midStack.append(numStack[idx][0] - numStack[idx][1])
            else :
                midStack.append(numStack[idx][0] * numStack[idx][1])

    return answer

print(solution("100-200*300-500+20"))