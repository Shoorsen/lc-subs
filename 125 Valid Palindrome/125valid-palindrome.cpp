class Solution {
public:
    bool isPalindrome(string s) {
        string n = "";
        for (char x : s) {
            if (std::isalnum(x)) {
                n+=tolower(x);
            }
        }
        std::cout << n << std::endl;
        int a = 0; int b = n.size()-1;
        while (a < b) {
            if (n[a] == n[b]) {
                a++; b--;
            } else {
                return false;
            }
        }
        return true;
    }
};