#프로그래머스 가사 검색

def solution(words, queries):
    answer = []

    words = sorted(words)


    for q in queries :
        count = 0
        for w in words :
            if len(q) != len(w) :
                continue
            flag = True

            for i in range(len(w)) :
                if w[i] != q[i] and q[i] != '?' :
                    flag = False
                    break
            if flag :
                count += 1
        answer.append(count)



    return answer