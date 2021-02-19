



def solution(dirs):
    answer = 0

    myMap = [[0 for _ in range(10)] for _ in range(10)]

    myList = []

    pos = [0,0]
    for d in dirs :
        if d == 'L':
            if pos[0] > -5 :
                left = str(pos[0])+str(pos[1])
                right = str(pos[0]-1)+str(pos[1])
                if left < right :
                    myList.append(str(left)+str(right))
                else :
                    myList.append(str(right) + str(left))

                pos[0] = pos[0]-1
        elif d == 'R' :
            if pos[0] < 5 :
                left = str(pos[0]) + str(pos[1])
                right = str(pos[0] +1) + str(pos[1])
                if left < right:
                    myList.append(str(left) + str(right))
                else:
                    myList.append(str(right) + str(left))
                pos[0] = pos[0] + 1
        elif d == 'D' :
            if pos[1] > -5 :
                left = str(pos[0]) + str(pos[1])
                right = str(pos[0]) + str(pos[1]-1)
                if left < right:
                    myList.append(str(left) + str(right))
                else:
                    myList.append(str(right) + str(left))
                pos[1] = pos[1] - 1
        elif d == 'U' :
            if pos[1] < 5 :
                left = str(pos[0]) + str(pos[1])
                right = str(pos[0]) + str(pos[1]+1)
                if left < right:
                    myList.append(str(left) + str(right))
                else:
                    myList.append(str(right) + str(left))
                pos[1] = pos[1] + 1

    mySet = list(set(myList))

    answer = len(mySet)
    return answer

print(solution("ULURRDLLU"))