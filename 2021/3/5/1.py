#leetcode 315. Count of Smaller Numbers After Self

class Solution:

    def seg(self,arr,tree,node,start,end):
        if start == end :
            tree[node] = arr[start]
            return tree[node]
        else :
            tree[node] = Solution.seg(arr,tree,node*2,start,(start+end)//2)+ Solution.seg(arr,tree,node*2+1,(start+end)//2+1,end)
            return tree[node]



    def countSmaller(self, nums) :





        return 1