class Solution:
    def generateTheString(self, n: int) -> str:
        if n%2==0:
            return 'o'*(n-1)+'h'
        else:
            return 'o'*n
    