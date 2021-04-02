
class Solution:
    def findReplaceString(self, S: str, indexes, sources, targets) -> str:



        answer = S
        arr = []

        plusIndex = 0
        for idx,source in enumerate(sources) :
            print(S[indexes[idx]:indexes[idx]+len(source)])
            if S[indexes[idx]:indexes[idx]+len(source)] == source :
                arr.append([indexes[idx],len(source),len(targets[idx]),targets[idx]])

        arr = sorted(arr)

        for a in arr :
            answer = answer[:a[0]+plusIndex] + a[3] + answer[a[0]+plusIndex+a[1]:]
            plusIndex += a[2]-a[1]
            print(answer,plusIndex)


        return answer