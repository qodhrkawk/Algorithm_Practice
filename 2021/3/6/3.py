

def solution():
    n = int(input())

    sqrt_5 = 5 ** (1/2)
    ans = (1 / sqrt_5 * ( ((1 + sqrt_5) / 2) ** n - ((1 - sqrt_5) / 2) ** n ))
    return int(ans)


print(solution())