
class Solution:
    def findReplaceString(self, S: str, indexes, sources, targets) -> str:



        answer = S

        plusIndex = 0
        for idx,source in enumerate(sources) :
            print(S[indexes[idx]:indexes[idx]+len(source)])
            if S[indexes[idx]:indexes[idx]+len(source)] == source :
                print(plusIndex)
                answer = answer[0:indexes[idx]+plusIndex] + targets[idx] + answer[indexes[idx]+plusIndex+len(source):]
                plusIndex += len(targets[idx])-len(source)


        return answer