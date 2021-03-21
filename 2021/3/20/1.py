


def solution(table, languages, preference):
    answer = ''

    myTable = []

    for t in table :
        myTable.append(t.split())

    print(myTable)

    candidate = []
    for t in myTable :
        maxScore = len(t)
        score = 0
        for idx,lan in enumerate(languages) :
            for i in range(1,len(t)) :
                if t[i] == lan :
                    score += (maxScore-i) * preference[idx]
        candidate.append([score,t[0]])


    candidate = sorted(candidate,key= lambda x: (-x[0],x[1]),reverse= True)
    print(candidate)
    answer = candidate[-1][1]


    return answer