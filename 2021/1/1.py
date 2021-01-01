n = int(input())
tmp = -1
answer = 0


while n!=tmp :
    answer = answer+1
    if tmp == -1 :
        tmp = n

    tmpStr = str(tmp)
    tmpSum = 0
    for s in tmpStr :
        tmpSum = tmpSum + int(s)
    tmp = int(tmpStr[-1]+str(tmpSum)[-1])


print(answer)