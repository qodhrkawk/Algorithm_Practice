

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:

        leftNode = l1
        rightNode = l2

        left = str(leftNode.val)
        right = str(rightNode.val)

        while leftNode.next != None :
            leftNode = leftNode.next
            left += str(leftNode.val)

        while rightNode.next != None :
            rightNode = rightNode.next
            right += str(rightNode.val)

        left = left[::-1]
        right = right[::-1]

        ans = str(int(left)+int(right))

        ans = ans[::-1]
        nodes = []
        answerNode = ListNode()
        lastNode = ListNode()
        for a in ans :
            nodes.append(ListNode(val= int(a)))

        for idx,node in enumerate(nodes) :
            if idx == 0 :
                answerNode = node
                lastNode = answerNode
            else :
                lastNode.next = node
                lastNode = node






        return answerNode