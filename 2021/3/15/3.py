#백준 보석 줍기







n,m = map(int,input().split())

jewel = []

for _ in range(n) :
    jewel.append(int(input()))


sums = [jewel[0]]

for i in range(1,len(jewel)) :
    sums.append(sums[i-1]+jewel[i])





ans = 0





if ans < 0 :
    print(0)
else :
    print(ans)
