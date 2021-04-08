#프로그래머스 추석 트래픽


def solution(lines):

    lines = sorted(lines)

    answer = 1
    executeTimes = []

    for line in lines :
        split = line.split()[1:]


        length = float(split[1][:-1])

        time = split[0].split(':')


        hour,minute,second = float(time[0]),float(time[1]),float(time[2])

        endTime = float(hour*3600+minute*60+second)
        startTime = float(hour*3600+minute*60+second-length+0.001)
        startTime = round(startTime,3)
        executeTimes.append([startTime,endTime])


    for idx,time in enumerate(executeTimes) :
        count = 1
        for i in range(len(executeTimes)) :
            if idx == i :
                continue
            else :
                if (executeTimes[i][0] <= time[0] and executeTimes[i][1] > time[0]) or (time[0]+1.0 > executeTimes[i][0] > time[0]) :
                    count += 1


        answer = max(count,answer)


        count = 1
        for i in range(len(executeTimes)):
            if idx == i :
                continue
            else :
                if (executeTimes[i][0] <= time[1] and executeTimes[i][1] > time[1]) or (
                        time[1] + 1.0 > executeTimes[i][0] > time[1]):
                    count += 1


        answer = max(count,answer)


    return answer



# print(solution(	["2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"]))