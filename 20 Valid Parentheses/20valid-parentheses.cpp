class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        std::map<char, char> mp = {{')', '('}, {'}', '{'}, {']', '['}};
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() || st.top() != mp[s[i]]){
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};