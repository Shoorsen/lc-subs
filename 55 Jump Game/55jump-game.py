class Solution:
    def canJump(self, nums: List[int]) -> bool:
        N = len(nums)
        min_indx = N-1
        for j in range(N-2, -1, -1):
            if (nums[j] + j >= min_indx):
                min_indx = j
        if min_indx == 0:
            return True
        return False



        