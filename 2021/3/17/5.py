#프로그래머스 파일명 정렬

def solution(files):
    answer = []

    arr = []

    for idx,file in enumerate(files) :
        start = -1
        end = -1
        for i in range(len(file)) :
            if file[i].isdigit() :
                if start == -1 :
                    start = i
                    end = i
                else :
                    end = i
            else :
                if start != -1 :
                    break

        head = file[0:start].lower()
        number = file[start:end+1]
        tail = file[end+1:]

        arr.append([head,number,tail,file,idx])

    arr = sorted(arr,key= lambda x:(x[0],int(x[1]),x[4]))

    for i in range(len(arr)) :
        answer.append(arr[i][3])


    # print(arr)




    return answer


print(solution( ["img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"]))