#프로그래머스 스킬트리

def solution(skill, skill_trees):
    answer = 0

    for tree in skill_trees :
        skillTmp = skill
        flag = True
        for i in range(len(tree)):
            if tree[i] in skillTmp :
                if tree[i] == skillTmp[0] :
                    skillTmp = skillTmp[1:]
                else :
                    flag = False
        if flag :
            answer += 1


    return answer