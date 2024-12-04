# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        if head == None:
            return head
        
        res = [head]
        
        while head.next:
            res.append(head.next)
            head= head.next
            
        res.reverse()
        
        for i in range(len(res)-1):
            res[i].next = res[i+1]
        
        res[-1].next = None
        
        return res[0]
        
        
