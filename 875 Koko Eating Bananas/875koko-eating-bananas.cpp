class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long kleft = 1; long long kright = *std::max_element(piles.begin(), piles.end());
        int ans = kright;
        while (kleft <= kright) {
            long long k = (kleft + kright) / 2;
            long long hours = 0;
            std::cout << k << std::endl;
            for (int i = 0; i < n; i++) {
                hours += (piles[i] + k - 1) / k;
            }
            if (hours > h) {
                kleft = k + 1;
            }
            else {
                kright = k - 1;
                if (k < ans) {
                    ans = k;
                }
            }
        }
        return ans;

    }
};