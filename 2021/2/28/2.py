class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        answer = 0


        for i in range(len(s)) :
            arr = []

            for j in range(i,len(s)):
                if s[j] in arr :
                    break
                else :
                    arr.append(s[j])

            answer = max(answer, len(arr))

        return answer




sol = Solution
print(Solution.lengthOfLongestSubstring(sol," "))