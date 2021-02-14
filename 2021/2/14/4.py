def solution(user_id, banned_id):
    answer = 0

    names = []


    for bi in banned_id :
        tmp = []

        for ui in user_id :
            if len(bi) == len(ui) :
                flag = True
                for i in range(len(bi)) :
                    if bi[i] != ui[i] and bi[i] != '*' :
                        flag = False
                        break
                if flag :
                    tmp.append(ui)

        names.append(tmp)

    print(names)




    return answer