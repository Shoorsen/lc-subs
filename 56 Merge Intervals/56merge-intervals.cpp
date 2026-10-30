class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        auto compareFunc = [](const std::vector<int>& a, const std::vector<int>& b) -> bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        };
        if (intervals.size() == 0) {
            return vector<vector<int>>();
        }
        std::sort(intervals.begin(), intervals.end(), compareFunc);
        std::vector<std::vector<int>> ans;
        int l = 0; int r = 0;
        int lspot = intervals[l][0]; int rspot = intervals[l][1];
        int lcheck = intervals[0][1];
        while (r < intervals.size()) {
            auto left = intervals[l];
            auto right = intervals[r];
            lcheck = max(left[1], lcheck);
            //Detect overlap
            if (lcheck >= right[0]) {
                rspot = max(lcheck, right[1]);
                // lcheck = max(left[1], lcheck);
            } else {
                vector<int> a = {lspot, rspot};
                ans.push_back(a);
                lspot = right[0];
                rspot = right[1];
            }
            l++;
            r++;
            if (l == r) {
                l--;
            }
        }
        ans.push_back(vector<int>{lspot, rspot});
        return ans;
    }
};


// [1,10], [2,3], [4,5], [6,7], [8,9]