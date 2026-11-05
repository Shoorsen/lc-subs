class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        std::sort(arr2.begin(), arr2.end());
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++) {
            int l = 0; int r = arr2.size()-1;
            int mid = (l+r)/2;
            int min_dist = d+1;
            while (l <= r) {
                mid = (l+r)/2;
                min_dist = std::min(min_dist, std::abs(arr1[i] - arr2[mid]));
                if (arr2[mid] == arr1[i]) {
                    break;
                }
                if (arr2[mid] > arr1[i]) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            cout << min_dist << endl;
            if (min_dist == d+1) {
                ans++;
            }
            // int closest = arr2[mid];
            // if (std::abs(arr1[i] - arr2[mid]) > d) {
            //     ans++;
            // }

        }
        return ans;
    }
};