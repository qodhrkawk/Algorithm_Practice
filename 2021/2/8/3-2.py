#프로그래머스 베스트앨범


def solution(genres, plays):
    answer = []

    sortDict = {}
    for idx,val in enumerate(genres) :
        if val in sortDict :
            sortDict[val] += plays[idx]
        else :
            sortDict[val] = plays[idx]

    sortDict = sorted(sortDict.items(), key=lambda item: -item[1])
    genreList = []
    for idx,value in enumerate(sortDict) :
        genreList.append(value[0])

    detailList = [[] for _ in range(len(genreList))]

    for idx, val in enumerate(genres):
        detailList[genreList.index(val)].append((plays[idx], idx))

    for detail in detailList :
        detail.sort(key= lambda x:(-x[0],x[1]))


    for idx,list in enumerate(detailList) :
        limit = min(len(list),2)
        for i in range(limit) :
            answer.append(list[i][1])


    return answer


print(solution(['classic', 'pop', 'classic', 'classic', 'pop'],[500,600,500,800,2500]))