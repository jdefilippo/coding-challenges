class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        if(len(height) == 0 or len(height) == 1):
            return 0
        
        if(len(height) == 2): 
            return min(height[0],height[1])
        
        
        # Handle case where all values are the same 
        uniformValue = height[0]
        for i in range(1, len(height),1):
            if(height[i] != uniformValue):
                uniformValue = height[i]
                break
                
        if(uniformValue == height[0]):
            return height[0]*(len(height)-1)
                
        
        i = 0 
        j = len(height) - 1
        curMin = min(height[i], height[j])
        
        if curMin == height[i]:
            curIdx = i
        else:
            curIdx = j 
        
        maxArea = curMin*(j-i) 
        
        foundBigger = False
        while(i < j): 
            if curIdx == i: 
                for k in range(curIdx+1, len(height) - 1, 1): 
                    if(height[k] == max(height[k], curMin)):
                        foundBigger = True
                        break
                        
                if(foundBigger):
                    i = k
                    foundBigger = False
                else: 
                    i += 1

            else:
                for k in range(curIdx-1,0,-1):
                    if(height[k] == max(height[k], curMin)):
                        foundBigger = True
                        break
                j = k
                
                if(foundBigger):
                    j = k 
                    foundBigger = False
                else:
                    j -= 1
            
             
            curMin = min(height[i], height[j])

            if curMin == height[i]:
                curIdx = i
            else:
                curIdx = j
                
                
            newArea = curMin*(j-i) 
            if(newArea > maxArea):
                maxArea = newArea
        
        return maxArea