from _collections import defaultdict


def solution(info, query):
    answer = []

    checkIdx = [0,2,4,6,7]
    n = len(info)
    dp = [False for _ in range(n)]

    dict = defaultdict(int)

    for inf in info :
        split = inf.split()
        num = split[-1]
        split.remove(num)
        dict[''.join(split)] = num




        # print(inf.split().join(''))



    #
    # for q in query :
    #     split = q.split()
    #
    #     count = 0
    #     for inf in info :
    #
    #         inf_s = inf.split()
    #         # print(inf_s)
    #         # print(split)
    #
    #         flag = True
    #         for idx,infs in enumerate(inf_s) :
    #             # print(infs,split[checkIdx[idx]])
    #             if split[checkIdx[idx]] == '-' :
    #                 continue
    #             if split[checkIdx[idx]].isalpha() :
    #                 if split[checkIdx[idx]] == infs :
    #                     continue
    #                 else :
    #                     flag = False
    #                     break
    #             else :
    #                 if int(split[checkIdx[idx]]) <= int(infs) :
    #                     continue
    #                 else :
    #                     flag = False
    #                     break
    #         if flag :
    #             count += 1
    #
    #     answer.append(count)


    return answer


print(solution(["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"],["java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]))