#프로그래머스 길 찾기 게임

from _collections import defaultdict
from _collections import deque

class Node :

    def __init__(self,val,x,y):
        self.val = val
        self.x = x
        self.y = y
    left,right = 0,0

class Tree :

    def __init__(self,root):
        self.root = root



def makeRelation() :



    return 1


def solution(nodeinfo):
    answer = [[]]

    yVals = []

    graph = deque()

    for idx,node in enumerate(nodeinfo) :
        y,x = node[1],node[0]
        yVals.append(y)
        graph.append([y,x,idx+1])

    yVals = list(set(yVals))

    yVals = sorted(yVals,reverse= True)

    graph = sorted(graph,key= lambda x: (x[0],-x[1]),reverse= True)

    parent = 0
    child = 1
    graphIdx = 0

    rootNode = Node(graph[0][2],graph[0][1],graph[0][0])

    queue  = deque
    queue.append(rootNode)


    while queue :
        front = queue.pop()
        if front.y != yVals[parent] :
            child = child+1
            parent = parent+1
        else :
            if queue[0].y == yVals[child] :
                newNode = Node(queue[0].)
                if queue[0].x < front.x :










    print(yVals)
    print(graph)





    return answer


print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]))