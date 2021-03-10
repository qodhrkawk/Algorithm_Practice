# leetcode 315. Count of Smaller Numbers After Self

import math


class Solution:

    def search(self,arr,num):

        if len(arr) == 0 :
            return 0

        if num <= arr[0] :
            return 0
        if num > arr[-1] :
            return len(arr)

        left = 0
        right = len(arr)
        mid = 0



        while left < right :

            mid = (left+right)//2
            if num > arr[mid] :
                left = mid + 1
            else :
                right = mid

        mid = (left+right)//2

        return mid







    def countSmaller(self, nums):

        ans = []

        nums = nums[::-1]


        arr = []

        for n in nums :
            idx = self.search(arr,n)
            ans.append(idx)
            arr.insert(idx,n)


        return ans[::-1]

