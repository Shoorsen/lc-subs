class Solution:
    def numJewelsInStones(self, J: str, S: str) -> int:
        list=[]
        for x in S:
            if x in J:
                list.append(x)
        return len(list)
            