class Solution:
    def reverse(self, x) -> int:
        s = str(x)
        if s[0] == '-' :
            s = s[1:]
            s = s[::-1]
            ans = int(s)*-1
            if ans < -1*pow(2,31) :
                return 0


            return ans

        else :
            s = s[::-1]
            ans = int(s)
            if ans >= pow(2,31) :
                return 0
            return ans