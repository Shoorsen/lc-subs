class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }
        auto compareFunc = [](const std::vector<int>& a, const std::vector<int>& b) -> bool {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            }
        };
        std::sort(intervals.begin(), intervals.end(), compareFunc);
        for (int i = 0; i < intervals.size()-1; i++) {
            auto cur = intervals[i];
            auto next = intervals[i+1];
            if (cur[0] <= next[0] && cur[1] > next[0]) {
                return false;
            }
        }
        return true;
    }
};