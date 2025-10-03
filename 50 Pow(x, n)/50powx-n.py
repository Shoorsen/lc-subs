class Solution:
    def myPow(self, x: float, n: int) -> float:
        ans = 1
        b = n
        m = x
        if (n < 0):
            b = ~n + 1
            m = 1/x
        
        while(b > 0):
            if (b & 1):
                ans = ans * m
            m = m * m
            b = b >> 1
        return ans

2.1


