class Solution:
    def trap(self, height: List[int]) -> int:
        a = 0
        b = 1
        water = 0
        to_add = 0
        mp = {}

        while (b < len(height)):
            if (height[b] >= height[a]):
                water += (b-a-1) * min(height[a], height[b]) - (to_add)
                to_add = 0
                mp[a] = b
                a = b
                b += 1
            else:
                to_add += height[b]
                b += 1
        a = len(height)-1
        b = len(height)-2
        to_add = 0
        while (b >= 0):
            if (height[b] >= height[a]):
                if (mp.get(b, -1) == a):
                    a = b
                    b -= 1
                    continue
                water += (a-b-1) * min(height[a], height[b]) - to_add
                to_add = 0
                a = b
                b -= 1
            else:
                to_add += height[b]
                b -= 1
        return water

