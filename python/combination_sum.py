def backtrack(candidates, target, solutionSet, runningSum, candidateSolution):
    if(runningSum > target):
        return    
    elif(runningSum == target): 
        #if candidateSolution not in solutionSet:
        #    solutionSet.append(candidateSolution)
        newKey = ""
        for i in candidateSolution:
            newKey += str(i)        
        if newKey not in solutionSet:
            solutionSet[newKey] = [elem for elem in candidateSolution]
            solutionSet[newKey].sort()
    else:
        for j in range(0,len(candidates),1):
            candidateSolution.append(candidates[j])
            runningSum += candidates[j] 
            backtrack(candidates, target, solutionSet, runningSum, candidateSolution)
            candidateSolution.pop()
            runningSum -= candidates[j] 

class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        solutionSet = []
        solutionDict = {}
        backtrack(candidates, target, solutionDict, 0, [])
        #print(solutionDict)
        #print(len(solutionDict.keys()))
        for key in solutionDict:
            #tmp = solutionDict[key].sort()
            if solutionDict[key] not in solutionSet:
                solutionSet.append(solutionDict[key])
        return solutionSet