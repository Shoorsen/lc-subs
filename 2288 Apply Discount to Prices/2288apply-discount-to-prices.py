class Solution:
    def discountPrices(self, sentence: str, discount: int) -> str:
        
        def discounter(word):
            if (word[0] == '$' and word[1:].isnumeric()):
                price = int(word[1:])
                price *= 0.01 * (100-discount)
                return f'${price:.2f}'
            return word



        discounts = []
        for word in sentence.split(' '):
            discounts.append(discounter(word))
        ans = ' '.join(discounts)

        return ans
