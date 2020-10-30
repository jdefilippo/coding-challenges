# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if not head: 
            return None
        if head.next is None: 
            return head
            
        iterNode = head        
        newHead = head.next
        
        prevFirst = None
        while(iterNode and iterNode.next):
            # Perform swap
            first       = iterNode
            second      = iterNode.next        
            first.next  = iterNode.next.next 
            second.next = first        
            iterNode    = iterNode.next # Pop out past the first two 
            # Zip Step
            if prevFirst is not None: 
                prevFirst.next = second
            prevFirst   = first # for zipping      
                
        return newHead