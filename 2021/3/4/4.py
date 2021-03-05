#leetcode 315. Count of Smaller Numbers After Self

class Solution:
    def countSmaller(self, nums) :
        newNum = []
        for n in nums :
            newNum.append(n+10000)
        dp = [0 for _ in range(20002)]

        ans = []
        for i in range(len(newNum)-1,-1,-1) :
            sum = 0
            dp[newNum[i]] += 1

            for j in range(newNum[i]) :
                sum += dp[j]
            ans.insert(0,sum)



        return ans


print(Solution.countSmaller(Solution(),nums=[-1,-2]))