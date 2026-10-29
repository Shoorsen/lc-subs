class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = 0; int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (nums[slow] != nums[fast]) {
            fast = nums[nums[fast]];
            slow = nums[slow];
        }
        int slow2 = 0;
        cout << nums[slow2] << endl;
        cout << nums[slow] << endl;
        while (slow2 != slow) {
            slow2 = nums[slow2];
            slow = nums[slow];
        }
        return slow;

        
    }
};