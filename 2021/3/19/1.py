#프로그래머스 방금 그곡

from _collections import defaultdict

def solution(m, musicinfos):
    answer = ''

    melody = ['C','C#','D','D#','E','F','F#','G','G#','A','A#','B']

    change = ['A','B','C','D','E','F','G','H','I','J','K','L']

    dic = defaultdict(str)


    for idx,m in enumerate(melody) :
        dic[m] = change[idx]



    musics = []

    search = ''

    for i in range(len(m)) :
        print(m[i],dic[m[i]])
        search += dic[m[i]]

    print('search')
    print(search)

    for music in musicinfos :
        infos = music.split(',')
        # print(infos)

        time = 60*(int(infos[1][0:2])-int(infos[0][0:2]))+int(infos[1][3:])-int(infos[0][3:])
        # print(infos[1][0:1])
        # print(time)

        lyric = infos[3]*(time//len(infos[3])) + infos[3][:time%len(infos[3])]
        if infos[3][time%len(infos[3])] == "#" :
            lyric += '#'

        print(lyric)

        musics.append([lyric,infos[2],time])

    maxTime = 0
    for music in musics :
        if m in music[0] :
            if maxTime < music[2] :
                maxTime = music[2]
                answer = music[1]
    if answer == '' :
        return "(None)"

    return answer



print(solution("A#BC#",["12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"]))