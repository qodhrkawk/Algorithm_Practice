

a, b = map(int,input().split())


def g(x,y) :
    mod = x % y
    while mod > 0 :
        x = y
        y = mod
        mod = x % y
    return y

def l(x,y) :
    return x*y//g(x,y)
print(g(a,b))
print(l(a,b))




