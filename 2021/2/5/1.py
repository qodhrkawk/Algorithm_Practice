#프로그래머스 전화번호 목록

def solution(phone_book):
    answer = True

    for i in range(len(phone_book)) :
        for j in range(len(phone_book)) :
            if i == j :
                continue
            else :
                if phone_book[i] < phone_book[j] :
                    if phone_book[i] == phone_book[j][0:len(phone_book[i])] :
                        return False


    return answer