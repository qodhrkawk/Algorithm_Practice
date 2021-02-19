
answer = ['ICN']

def dfs(n,depth,start,visited,ticArr,ticDict) :
    if n == depth :
        return True

    for idx in range(len(ticArr[start])) :

        if visited[start][idx] == 0 :
            visited[start][idx] = 1
            answer.append(ticArr[start][idx])
            if dfs(n,depth+1,ticDict[ticArr[start][idx]],visited,ticArr,ticDict) :
                return True
            answer.pop(-1)
            visited[start][idx] = 0

    return False




def solution(tickets):

    n = len(tickets)
    ticDict = {}

    ticArr = [[]]

    for tic in tickets :
        if tic[0] in ticDict :
            ticArr[ticDict[tic[0]]].append(tic[1])
        else :
            ticDict[tic[0]] = len(ticArr)
            ticArr.append([tic[1]])
        if tic[1] not in ticDict :
            ticDict[tic[1]] = len(ticArr)
            ticArr.append([])


    visited = [[] for _ in range(len(ticArr))]
    for i in range(len(ticArr)) :
        ticArr[i] = sorted(ticArr[i])
        for j in range(len(ticArr[i])) :
            visited[i].append(0)

    start = ticDict['ICN']
    dfs(n,0,start,visited,ticArr,ticDict)

    return answer


# print(solution([['ICN', 'SFO'], ['ICN', 'ATL'], ['SFO', 'ATL'], ['ATL', 'ICN'], ['ATL','SFO']]))
print(solution([['ICN', 'AAA'], ['ICN', 'BBB'], ['BBB', 'ICN']]))