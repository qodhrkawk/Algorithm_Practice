from itertools import product

class Solution:
    def kSmallestPairs(self, nums1, nums2, k: int) :



        ans = list(product(nums1,nums2))

        ans = sorted(ans,key= lambda x: x[0]+x[1])


        return ans[:k]