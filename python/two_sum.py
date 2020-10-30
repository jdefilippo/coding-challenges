class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # naive O(n)^2 solution. 
        # Pseudocode 
        # For each number x in list: 
        #     For each number y that follows:
        #        if x+y==target:
        #             return [index_x, index_y]
        
        # O(n^2),O(1) solution 
        #for i in range(0,len(nums)):
        #    for j in range(i+1,len(nums)):
        #        if nums[i] + nums[j] == target: 
        #            return [i,j]
       # 
       # return [] 
    
        # hash table solution.
        #O(n), O(n)
        found = {} 
        for i in range(0,len(nums)):
            found[nums[i]] = i  
        
        for j in range(0, len(nums)):
            complement = target-nums[j]
            if complement in found and found[complement] != j:
                return [j,found[complement]]
            
        return []