# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import heapq
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:       
        '''
        1. Go through k lists and append the head elements
        2. Pop off the min elements from the list 
               Add this to the next field in the constructed new list 
               Add the next field of the min element to the heap. 
        
        tmp <- NULL
        head = temp
        while(h is not empty)
             newElem = pop(h)
             if newElem.next is not None: 
                 h.push(newElem.next)
             # Get rid of the next pointer in elem
             newElem.next = NULL
             tmp.next = newElem
             tmp = tmp.next        
        '''
                
        # Initialize the heap 
        h = [] 
        tie = 0 # Breaks ties
        for i in range(0, len(lists),1):
            if(lists[i] is not None):
                heappush(h,(lists[i].val,tie, lists[i]))
            tie += 1 
        
        head = None 
        
        # Do logic to put the first element on the list
        if(h):
            poppedElem = heappop(h)   
            poppedNode = poppedElem[2] 
            
            if poppedNode.next is not None: 
                heappush(h,(poppedNode.next.val,tie,poppedNode.next))
            
            tie += 1
            head = poppedNode
            
        tmp = head
        while(h): 
            poppedElem = heappop(h)   
            poppedNode = poppedElem[2] 
            if poppedNode.next is not None: 
                heappush(h,(poppedNode.next.val,tie,poppedNode.next))
                tie += 1 
            poppedNode.next = None            
            tmp.next = poppedNode            
            tmp      = tmp.next
            
        return head