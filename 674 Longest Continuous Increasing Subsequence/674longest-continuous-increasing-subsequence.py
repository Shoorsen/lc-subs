class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        result = 0
        front = 1
        if len(nums)==1:
            return 1
        else:
            for i in range(len(nums)-1):
                if nums[i+1]>nums[i]:
                    front+=1
                else:
                    front=1
                result = max(result, front)
            return result
        
        