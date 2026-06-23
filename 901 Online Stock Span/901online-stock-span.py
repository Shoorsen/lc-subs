class StockSpanner:

    def __init__(self):
        self.st = []
        self.index = 0
    def next(self, price: int) -> int:
        diff = 1
        while (len(self.st)>0 and price >= self.st[-1][1]):
            top = self.st.pop()

        if (len(self.st) == 0):
            diff = self.index + 1
        else:
            diff = self.index - self.st[-1][0]

        self.st.append((self.index, price))
        self.index += 1
        return diff



# Your StockSpanner object will be instantiated and called as such:
# obj = StockSpanner()
# param_1 = obj.next(price)

