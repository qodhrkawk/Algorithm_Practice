#프로그래머스 불량 사용자

from itertools import permutations



def check(user,ban) :
    for i in range(len(user)) :
        if len(user[i]) != len(ban[i]) :
            return False
        for j in range(len(user[i])) :
            print(i,j)
            if ban[i][j] == '*':
                continue
            if user[i][j] != ban[i][j] :
                return False
    return True




def solution(user_id, banned_id):


    ans = []
    for perm in permutations(user_id,len(banned_id)) :
        if check(perm,banned_id) :
            perm = set(perm)
            if perm not in ans :
                ans.append(perm)





    return len(ans)