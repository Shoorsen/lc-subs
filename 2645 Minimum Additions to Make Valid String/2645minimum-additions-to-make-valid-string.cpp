class Solution {
public:
    int addMinimum(string word) {
        if (word.size() == 1) {
            return 2;
        }
        else if (word.size() == 2) {
            if (word == "ab" || word == "bc" || word == "ac") {
                return 1;
            }
            else {
                return 4;
            }
        }

        std::string t = "abc";
        int ans = 0;
        int n = word.size();
        std::string w = "";
        int i = 0;
        int ptr = 0;
        while (i < n || w.back() != 'c') {
            if(t[ptr % 3] > word[i]) {
                ans++;
                w += t[ptr % 3];
                ptr++;
            }
            else if (t[ptr % 3] < word[i]) {
                ans++;
                w += t[ptr % 3];
                ptr++;
            }
            else {
                w += word[i];
                i++;
                ptr++;
            }
        }
        std::cout << w << std::endl;
        return ans;
    }
};


