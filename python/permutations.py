def backtracking(solSet, nums,n,res,visited):
    if len(res) == n:
        solSet.append([x for x in res])
    else:
        for i in range(0,len(nums),1): 
            if(not visited[i]):
                res.append(nums[i])
                visited[i] = True
                backtracking(solSet,nums,n,res, visited)
                res.pop()
                visited[i] = False
            

class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        solSet = [] 
        n = len(nums)
        res = []     
        visited = [False for i in range(len(nums))]
        backtracking(solSet,nums,n,res,visited)
        return solSet