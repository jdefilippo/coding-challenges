class Solution:
    def jump(self, nums: List[int]):
        jumpIdx = 1
        j = 0 
        res = [0 for i in range(0,len(nums))]
        while(j < len(nums)):
            if res[len(nums)-1] != 0: 
                return res[len(nums)-1]            
            jumpLenPosition = nums[j]
            while(jumpIdx < len(nums) and jumpIdx-j <= jumpLenPosition):
                res[jumpIdx] = res[j] + 1
                jumpIdx      += 1
            j += 1
        return 0