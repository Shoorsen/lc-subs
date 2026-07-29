class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<std::pair<int, int>> v;
        int n = position.size();
        for (int i = 0; i < n; i++) {
            v.push_back({position[i], speed[i]});
        }
        std::sort(v.rbegin(), v.rend());
        // for (int i = 0; i < n; i++) {
        //     std::cout << v[i].first << " " << v[i].second << std::endl;
        // }
        int num_fleets = 0;
        double prev_hours = -1;
        for(int i = 0; i < n; i++) {
            int pos = v[i].first;
            int mph = v[i].second;
            double hours = (double) (target - pos) / mph;
            if (hours > prev_hours) {
                prev_hours = hours;
                num_fleets += 1;
            }
        }
        return num_fleets;

     
    //  [10, 8, 5, 3, 0]
    //  [2, 4, 1, 3, 1]
    //  [1, 1, 7, 3, 12]


    // [4, 2, 0]
    // [1, 2, 4]
    // [96, 49, 25]
    }
};