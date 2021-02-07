#프로그래머스 주식가격

def solution(prices):
    answer = [0 for _ in range(len(prices))]

    priceStack = []

    for i in range(len(prices)) :
        while len(priceStack) > 0 and prices[priceStack[-1]] > prices[i] :
            index = priceStack.pop()
            answer[index] = i - index
        priceStack.append(i)


    while len(priceStack) > 0 :
        index = priceStack.pop()
        answer[index] = len(prices) - index - 1

    answer[-1] = 0
    return answer