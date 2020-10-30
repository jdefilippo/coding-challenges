class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        j = len(nums)-1
        for i in range(len(nums)-1,-1,-1):
            if (nums[i] <= 0):
                nums[i], nums[j] = nums[j], nums[i]
                j -= 1
        end = j+1
        for i in range(0,end,1):            
            val = abs(nums[i]) 
            if(val > end):
                continue
            if (nums[val-1] > 0): 
                nums[val-1] = -nums[val-1]
        
        for i in range(0,end,1):   
            if nums[i] > 0:
                return i+1
        return end+1
