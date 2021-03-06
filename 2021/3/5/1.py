#leetcode 315. Count of Smaller Numbers After Self

class Solution:

    def seg(self,arr,tree,node,start,end):
        if start == end :
            tree[node] = arr[start]
            return tree[node]
        else :
            tree[node] = Solution.seg(arr,tree,node*2,start,(start+end)//2)+ Solution.seg(arr,tree,node*2+1,(start+end)//2+1,end)
            return tree[node]

    def segSum(self,tree,node,start,end,left,right):
        if left > end or right < start :
            return 0
        if left <= start and end <= right :
            return tree[node]

        return Solution.segSum(tree,node*2,start,(start+end)//2,left,right) + Solution.segSum(tree,node*2+1,start,(start+end)//2+1,left,right)


    def countSmaller(self, nums) :

        tree = [0 for _ in range(len(nums)*2)]

        Solution.seg(nums,tree,1,1,len(nums))
        ans = []
        for i in range(1,len(nums)+1) :
            ans.append(Solution.segSum(tree,i,))


        return 1