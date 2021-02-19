
def findMin(part) :

    return min(part)



def solution(a):
    answer = 0
    leftMin = a[0]

    mins = [0 for _ in range(len(a))]
    mins[-1] = a[-1]
    for i in range(len(a)-2,0,-1) :
        mins[i] = min(mins[i+1],a[i])


    for idx,num in enumerate(a) :
        if idx == 0 or idx == len(a)-1 :
            answer += 1
        else :
            leftMin = min(leftMin,a[idx-1])
            rightMin = mins[idx+1]

            if num < leftMin or num < rightMin :

                answer+=1




    return answer