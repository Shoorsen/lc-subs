class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 1) {
            return heights[0];
        }
        // std::vector<std::pair<int, int>> v;
        // for (int i = 0; i < heights.size(); i++) {
        //     v.push_back((std::make_pair(heights[i], i)));
        // }
        std::vector<int> choices(n, 1);
        std::stack<std::pair<int,int>> st;
        st.push(std::make_pair(0, heights[0]));
        for (int i = 1; i < n; i++) {
            int cur_height = heights[i];
            int first = 0;
            int popped = 0;
            while (!st.empty() && st.top().second > cur_height) {
                std::pair<int,int> pi = st.top();
                first = pi.first;
                choices[pi.first] += i - pi.first - 1;
                st.pop(); popped++;
            }
            if (popped) {
                choices[i] += choices[first];
            }
            st.push(std::make_pair(i, cur_height));
        }
        int end = (st.top()).first;
        while (!st.empty()) {
            std::pair<int,int> top = st.top();
            int first = top.first;
            int second = top.second;
            // std::cout << "Pair: <" << first << ", " << second << ">" << std::endl;

            st.pop();
            if (end != first) {
                choices[first] += (end - first); // * second;
            }

        }
        for (int i = 0; i < n; i++) {
                // std::cout << "choices[" << i << "]: " << choices[i] << std::endl <<std::endl;
            choices[i] *= heights[i];
        }
        return *std::max_element(choices.begin(), choices.end());
    }
};

