class Solution:
    def longestCommonPrefix(self, strs) -> str:
        mini = 201
        for s in strs:
            mini = min(len(s),mini)
        if len(strs) == 0 :
            return ''
        answer = ''
        if mini == 0 :
            return ''
        for i in range(mini) :
            tmp = strs[0][i]
            flag = True
            for s in strs :
                if tmp != s[i] :
                    flag = False
                    break

            if flag == False :
                return answer
            else :
                answer += tmp
        return answer