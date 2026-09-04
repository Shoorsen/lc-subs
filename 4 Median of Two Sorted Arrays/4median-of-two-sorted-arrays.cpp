class Solution {
public:
    double solve(const vector<int>& smaller, const vector<int>& larger) {
        int mid = (smaller.size()-1)/2;
        int total = (smaller.size() + larger.size());
        int l = 0; int r = smaller.size();
        int m1 = (r+l)/2; //index at -1 to get this many elements
        int m2;
        int smaller_left, smaller_right;
        int larger_left, larger_right;
        while (true) {
            m1 = (r + l)/2;
            m2 = total/2-m1; //index at -1
            
            if (m1 == 0) {
                smaller_left = -1000001;
            } else {
                smaller_left = smaller[m1-1];
            }
            if (m1 == smaller.size()) {
                smaller_right = 1000001;
            } else {
                smaller_right = smaller[m1];
            }

            if (m2 == 0) {
                larger_left = -1000001;
            } else {
                larger_left = larger[m2-1];
            }
            if (m2 == larger.size()) {
                larger_right = 1000001;
            } else {
                larger_right = larger[m2];
            }

            // std::cout << "total: " << total << std::endl;
            // std::cout << "smaller_left: " << smaller_left <<std::endl;
            // std::cout << "smaller_right: " << smaller_right << std::endl;
            // std::cout << "larger_left: " << larger_left << std::endl;
            // std::cout << "larger_right: " << larger_right << std::endl << std::endl; 
            if (smaller_right < larger_left) {
                // move m1 up
                l = m1+1;
            }
            else if (smaller_left > larger_right) {
                // move m1 down
                r = m1-1;
            }
            else {
                if ((smaller.size() + larger.size())%2==0) {
                    return ((double)std::max(smaller_left, larger_left) + (double)std::min(smaller_right, larger_right))/2;
                }
                else {
                    return std::min(smaller_right, larger_right);
                }
            }
            // adjust m2 based on m1 hops
        }
        return -1;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // if (nums1.empty()) {
        //     return nums2[(nums2.size()-1)/2];
        // }
        // if (nums2.empty()) {
        //     return nums1[(nums1.size()-1)/2];
        // }

        if (nums1.size() < nums2.size()) {
            return solve(nums1, nums2);
        }

        return solve(nums2,nums1);
    }
};