# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        cur = head 
        numNodes = 0 
        while(cur): 
            cur = cur.next 
            numNodes += 1
        nodeToDelete = numNodes - n 
        
        #print(nodeToDelete)
        cur = head
        numNodes = 0
        prev = None
        while(cur): 
            if(numNodes == nodeToDelete):
                #print("here")
                if(prev):
                    prev.next = cur.next
                else:
                    head = cur.next
            prev = cur
            cur = cur.next
            numNodes += 1
        
        return head