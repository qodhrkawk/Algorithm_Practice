#프로그래머스 줄 서는 방법



def solution(n, k):

    factorial = [1 for _ in range(21)]
    answer = []
    for i in range(2,21) :
        factorial[i] = i*factorial[i-1]

    people = [i for i in range(1,n+1)]


    tmp = n-1

    for i in range(tmp,1) :
        if factorial[i] < k :
            tmp = i
            break

    while tmp > 0 :
        count = 0
        while factorial[tmp] < k :
            k -= factorial[tmp]
            count += 1
        answer.append(people[count])
        people.remove(people[count])
        tmp -= 1

    answer.append(people[0])


    return answer


print(solution(3,5))