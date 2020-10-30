class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        for i in range(0,len(nums),1):
            if nums[i] == target:
                return i 
            elif nums[i] > target:
                if i == 0:
                    return 0
                else:
                    return i

        return len(nums)