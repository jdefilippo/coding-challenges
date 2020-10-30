class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        # Two pointer approach
        i = 0 
        for j in range(0, len(nums),1):
            if nums[i] != nums[j]: 
                i += 1 
                nums[i] = nums[j]
        return i+1 