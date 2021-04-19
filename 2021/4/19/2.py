from _collections import defaultdict

def solution(s):

    mySet = set()

    s = s.replace("{","")
    s = s.replace("}","")

    s = s.split(",")

    answer = []
    tmpLen = 0

    dict = {}

    s = map(int,s)

    for elem in s:
        if elem in dict :
            dict[elem] += 1
        else :
            dict[elem] = 1

        # mySet.add(elem)


        # if tmpLen != len(mySet) :
        #     answer.append(int(elem))
        #     tmpLen = len(mySet)
    # print(dict)


    answer = sorted(dict,key= lambda x: dict[x],reverse= True)




    return answer


print(solution("{{2},{2,1},{2,1,3},{2,1,3,4}}"))