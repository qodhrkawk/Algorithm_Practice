#leetcode 315. Count of Smaller Numbers After Self

import math

class Solution:
    tree = []
    def seg(self,arr,tree,node,start,end,num):
        if start == end:
            if arr[start] < num :
                tree[node] += 1
            return tree[node]
        else:
            tree[node] = self.seg(arr, tree, node * 2, start, (start + end) // 2,num) + self.seg(arr, tree, node * 2 + 1,
                                                                                   (start + end) // 2 + 1, end,num)
            return tree[node]


    def segSum(self,tree,node,start,end,left,right):
        if left > end or right < start :
            return 0
        if left <= start and right >= end :
            return tree[node]
        else :
            return self.segSum(tree,node*2,start,(start+end)//2,left,right) + self.segSum(tree,node*2+1,(start+end)//2+1,end,left,right)




    def countSmaller(self, nums) :

        ans = []

        n = len(nums)

        h = math.ceil(math.log2(n))

        tree_size = 1<<(h+1)





        for i in range(n) :
            tree = [0 for _ in range(tree_size)]
            self.tree = tree
            print(tree)
            Solution.seg(self, nums, tree, 1, 0, n - 1,nums[i])
            print(tree)
            ans.append(Solution.segSum(self,tree,1,0,n-1,i,n-1))

        return ans


print(Solution.countSmaller(Solution(),[5,2,6,1]))