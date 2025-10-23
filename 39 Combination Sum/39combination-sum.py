class Solution:
    def l(self, i, v, sum, candidates, t, length):
        if (sum > t or i >= length):
            return []
        if (sum == t):
            return [v.copy()]
        else:
            passer = v.copy()
            jj = v.copy()
            passer.append(candidates[i])
            return Solution.l(self, i, passer, sum + candidates[i], candidates, t, length) + Solution.l(self, i+1, jj, sum, candidates, t, length)
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        i = 0
        v = []
        sum = 0
        return Solution.l(self, i, v, sum, candidates, target, len(candidates))
