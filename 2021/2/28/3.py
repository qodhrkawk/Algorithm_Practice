class Solution:
    def findMedianSortedArrays(self, nums1, nums2) -> float:

        arr = []
        i = 0
        j = 0

        while i < len(nums1) or j < len(nums2) :
            if i >= len(nums1) :
                arr.append(nums2[j])
                j += 1
            elif j >= len(nums2) :
                arr.append(nums1[i])
                i += 1
            else :
                if nums1[i] < nums2[j] :
                    arr.append(nums1[i])
                    i += 1
                else :
                    arr.append(nums2[j])
                    j += 1

        answer = 0.0
        if len(arr)%2 != 0 :
            answer = arr[len(arr)//2]
        else :
            answer += arr[len(arr)//2]
            answer += arr[len(arr)//2-1]
            answer /= 2

        print(arr)
        round(answer,4)

        return answer