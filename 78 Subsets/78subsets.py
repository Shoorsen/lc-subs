class Solution:
    def subs(self, num: int, nums: List[List[int]]) -> List[List[int]]:
        ans = nums.copy() #[[]]
        for x in nums:
            ans.append([num] + x)
        # if (nums == [[]]):
        #     ans.append([num])
        return ans
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        if (len(nums) == 0):
            return [[]]
        
        # sub = [nums[len(nums)-1]]
        # ans.append(sub)
        # if (len(nums) == 1):
        #     return ans
        ans = [[]]
        for i in range(len(nums)-1, -1, -1):
            ans = Solution.subs(self, nums[i], ans)
        return ans