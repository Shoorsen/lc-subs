class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        st = []
        st.append((0, temperatures[0]))
        output = [0 for i in range(len(temperatures))]
        for (i, temp) in enumerate(temperatures):
            if i == 0:
                continue
            while (len(st) > 0 and temp > st[-1][1]):
                top = st.pop()
                output[top[0]] = i - top[0]
            
            st.append((i, temp))
        return output
        