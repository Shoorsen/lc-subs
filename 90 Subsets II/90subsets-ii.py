class Solution:
    def subs(self, num, nums:List[List[int]]) -> List[List[int]]:
        ans = [] #[[]]
        for x in nums:
            ans.append([num] + x)
        return ans

    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        if (len(nums) == 0):
            return [[]]
        nums.sort()
        #[1, 1, 2, 2]

        # sub = [nums[len(nums)-1]]
        # ans.append(sub)
        # if (len(nums) == 1):
        #     return ans
        ans = [[]]
        # subs = [nums[len(nums)-1]]
        sub = [[]]
        for i in range(len(nums)-1, -1, -1):
            if (i == len(nums)-1):
                sub = Solution.subs(self, nums[i], sub) #[[2]]
            elif (nums[i] == nums[i+1]): 
                sub = Solution.subs(self, nums[i], sub)
            else:
                # print(ans)
                sub = Solution.subs(self, nums[i], ans)
                # print(ans)
            ans += sub
        return ans