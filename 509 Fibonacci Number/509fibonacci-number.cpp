#include<map>
class Solution {
public:
    int mp[31] = {0, 1};
    int fib(int n) {
        if (n == 0) {
            return 0;
        }
        if (mp[n] == 0) {
            mp[n] = fib(n-1) + fib(n-2);
        }
        return mp[n];
    }
};