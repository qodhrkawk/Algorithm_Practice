# 프로그래머스 길 찾기 게임
import math

preorderAnswer = []


def preorder(tree,idx) :
    if idx >= len(tree) or tree[idx] == 0:
        return

    preorderAnswer.append(tree[idx])
    preorder(tree,2*idx)
    preorder(tree,2*idx+1)




def solution(nodeinfo):
    answer = [[]]

    tree = []
    ys = []

    for idx,node in enumerate(nodeinfo) :
        if node[1] not in ys :
            ys.append(node[1])
        tree.append([node[1],node[0],idx+1])



    tree = sorted(tree,key= lambda x: (-x[0],x[1]))
    print(tree)

    structure = [[] for _ in range(tree[0][0]+1)]
    for t in tree :
        structure[t[0]].append([t[1],t[2]])


    print(structure)



    totalTree = [0 for _ in range(2 * pow(2, tree[1][0]+1))]



    lastY = tree[0][0]
    totalTree[1] = tree[0][2]
    lastIdx = 1

    queue = tree[:]
    indices = [1]

    for i in range(1,len(tree)) :

        while structure[lastY] == [] :
            lastY -= 1

        print(lastY)

        if structure[lastY][0][0] > tree[i][1] :
            totalTree[indices[0]*2] = tree[i][2]
            indices.append(indices[0]*2)

        else :
            totalTree[indices[0]*2+1] = tree[i][2]
            structure[lastY].pop(0)
            indices.append(indices[0] * 2+1)
            indices.pop(0)
        print(totalTree)



    print(totalTree)




    preorder(totalTree,1)
    print(preorderAnswer)


    return answer


print(solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]))