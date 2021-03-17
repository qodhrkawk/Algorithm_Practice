class Solution:
    def propotion(self,left,right,nums):
        mid = (left+right)//2
        if 0 < mid < len(nums) - 1:
            if nums[mid] > nums[mid + 1] and nums[mid] > nums[mid - 1]:
                return mid
        else :
            return -1
        if mid-1 >= left :
            self.propotion(left,mid-1,nums)
        if mid+1 <= right :
            self.propotion(mid+1,right,nums)

        return -1


    def findPeakElement(self, nums) :
        if len(nums) == 1 :
            return 0
        nums.append(-float('inf'))


        left,right = 0,len(nums)-1

        while left <= right :
            mid = (left+right)//2
            print(left,right,mid)

            if 0 < mid < len(nums)-1 :
                if nums[mid] > nums[mid+1] and nums[mid] > nums[mid-1] :
                    return mid
                else :
                    right = mid-1
            else :
                break




        return 0





print(Solution.findPeakElement(Solution,[1,3,2,1]))