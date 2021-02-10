#프로그래머스 단어 변환


def solution(begin, target, words):

    visited = {i:False for i in words}
    ans = 0
    stack = [begin]

    if target not in words :
        return 0

    while len(stack) :
        top = stack.pop()
        if top == target :
            return ans

        for word in words :
            count = 0
            for i in range(len(word)) :
                if word[i] != top[i] :
                    count += 1
            if count == 1 :
                if visited[word] == False :
                    visited[word] = True
                    stack.append(word)

        ans += 1








    return ans


print(solution('hit','cog',['hot', 'dot', 'dog', 'lot', 'log', 'cog']))