class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int cur_area = 0;
        int new_area = 0;
        int a = 0; int b = height.size() - 1;
        while (a != b) {
            cur_area = min(height[a], height[b]) * (b-a);
            if (cur_area > max_area) {
                max_area = cur_area;
            }
            if (height[a] < height[b]) {
                a++;
            } else {
                b--;
            }
        }
        return max_area;
    }
};