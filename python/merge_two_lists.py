# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        def recursiveMerge(l1, l2):  
            
            tmp = None       
            
            if not l1: 
                return l2
            if not l2: 
                return l1
            
            if l1.val <= l2.val:
                tmp = l1                 
                tmp.next = recursiveMerge(l1.next,l2)
            else:
                tmp = l2
                tmp.next = recursiveMerge(l1,l2.next)
            
            return tmp
        
        return recursiveMerge(l1,l2)