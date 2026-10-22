class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size()) {
            return false;
        }
        //letter: current_count, s1_total_count
        std::unordered_map<char, int> s1_counts;
        std::unordered_map<char, int> perm_counts;

        for (int i = 0; i < s1.size(); i++) {
            s1_counts[s1[i]]++;
        }
        for (int i = 0; i < s1.size()-1; i++) {
            perm_counts[s2[i]]++;
        }


        for (int i = s1.size()-1; i < s2.size(); i++) {
            std::cout << i << " " << s2[i] << endl;
            perm_counts[s2[i]]++;
            if (i > s1.size()-1) {
                perm_counts[s2[i-s1.size()]]--;
            }
            bool passed = true;
            for (const auto& pair : perm_counts) {
                if(s1_counts[pair.first] != pair.second) {
                    passed = false;
                    break;
                }
            }
            if (passed) {
                return passed;
            }
        }
        return false;
    }
};