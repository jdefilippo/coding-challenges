class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        i,j = 0,0
        
        n = len(nums)
        nums.sort()
        res = [] 
        #print(nums)
        seen = set()
        for k in range(0,n):
            i = k+1
            j = n-1
            while(i < j and i < n and j < n):
                #print(k,i,j)
                if (nums[i] + nums[j] + nums[k] == 0): 
                    if (nums[i], nums[j], nums[k]) not in seen: 
                        seen.add((nums[i], nums[j], nums[k]))
                        res.append([nums[k],nums[i],nums[j]])
                    i += 1
                    j -= 1
                elif nums[i] + nums[j] +nums[k] < 0:
                    i += 1 
                else:
                    j -= 1             
        #print(seen)
        return res