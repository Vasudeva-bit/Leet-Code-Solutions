class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        count = {n:0 for n in nums}
        
        for n in nums:
            count[n] += 1
        
        result = []
        perm = []
        def dfs():
            if(len(nums) == len(perm)):
                result.append(perm.copy())
                return
            
            for i in count:
                if count[i] > 0:
                    count[i] -= 1
                    perm.append(i)
                    
                    dfs()
                    
                    count[i] += 1
                    perm.pop()
        dfs()
        return result
            