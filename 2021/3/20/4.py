import re

def search(infos,parents,id,result) :

    if parents[id] == 0 :
        result.append(infos[id-1][1])
    else :
        search(infos,parents,parents[id],result)
        result.append(infos[id-1][1])

    return result


def solution(data, word):
    answer = []
    infos = []

    for d in data :
        infos.append(d.split())

    n = len(data)
    parents = [0 for _ in range(n+1)]

    keywords = ['' for _ in range(n+1)]


    for info in infos :

        parents[int(info[0])] = int(info[2])
        keywords[int(info[0])] = info[1]


    pCount = [0 for _ in range(n+1)]
    for i in range(1,n+1) :
        pCount[parents[i]] += 1

    dolls = []
    for i in range(1,n+1) :
        if pCount[i] == 0 :
            dolls.append(i)


    candidiate = []

    for idx,key in enumerate(keywords) :
        if idx in dolls :
            if word in key :
                candidiate.append([idx,0,0])

    if len(candidiate) == 0 :
        answer.append("Your search for ("+word+") didn't return any results")



    for can in candidiate :
        if keywords[can[0]] == word :
            res = search(infos,parents,can[0],[])
            answer.append('/'.join(res))
            candidiate.remove(can)

    for can in candidiate :
        can[1] = keywords[can[0]].count(word)
        findIt = re.finditer(word,keywords[can[0]])
        tmp = []
        for match in findIt :
            tmp.append(match.start())
        can[2] = tmp

    candidiate = sorted(candidiate,key= lambda x:(-x[1],x[2],x[0]))

    for can in candidiate :
        res = search(infos, parents, can[0], [])
        answer.append('/'.join(res))

    return answer