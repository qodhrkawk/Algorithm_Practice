#프로그래머스 캐시

def solution(cacheSize, cities):
    answer = 0


    cache = []
    if cacheSize == 0 :
        return 5*len(cities)

    for c in cities :
        c = c.lower()
        if c in cache :
            answer += 1
            cache.remove(c)
            cache.append(c)
        else :
            answer += 5
            if len(cache) < cacheSize :
                cache.append(c)
            else :
                cache.pop(0)
                cache.append(c)



    return answer
