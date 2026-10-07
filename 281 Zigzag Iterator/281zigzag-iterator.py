class ZigzagIterator:
    def __init__(self, v1: List[int], v2: List[int]):
        self.l1 = v1 
        self.l2 = v2
        self.l1Idx = 0
        self.l2Idx = 0 
        self.first = True

    def next(self) -> int:
        if not self.hasNext(): 
            return False 
        
        if len(self.l1) != self.l1Idx and len(self.l2) != self.l2Idx: 
            if self.first:
                ans = self.l1[self.l1Idx]
                self.l1Idx += 1
            else:
                ans = self.l2[self.l2Idx]
                self.l2Idx += 1
            
            self.first = not self.first

        elif self.l1Idx < len(self.l1):
            ans = self.l1[self.l1Idx]
            self.l1Idx += 1
        else:
            ans = self.l2[self.l2Idx]     
            self.l2Idx += 1
        return ans

    def hasNext(self) -> bool:
        return self.l1Idx < len(self.l1) or self.l2Idx < len(self.l2)

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())