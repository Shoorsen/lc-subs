class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int l = 0;
        int ans = 0;
        for (int i = 0; i < brackets.size(); i++) {
            auto bracket = brackets[i];
            int upper = bracket[0];
            int percent = bracket[1];

            ans += (std::min(upper, income)-l) * percent;
            l = upper;
            if (l > income) {
                break;
            }

        }
        return (double) ans * 0.01;
    }
};