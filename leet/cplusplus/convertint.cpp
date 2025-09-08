//LeetCode No. 1317 Convert Integer to the Sum of Two Non-Negative Integers
#include <iostream>
using namespace std;
class Solution {
    public:
        vector<int> getNoZeroIntegers(int n) {
            int x = 1;
            int y = n-1;
            vector<int> ans = {x,y};
            while (x <= y) {
                if (x + y == n) {
                    if (containsZero(x) || containsZero(y)) {
                        x += 1;
                        y -= 1;
                    } else {
                        break;
                    };
                } else {
                x += 1;
                y -= 1;
                };
            };
            ans[0] = x;
            ans[1] = y;
            return ans;
        };
        bool containsZero(int n) {
        if (n == 0) return true; 
        n = std::abs(n);
        while (n > 0) {
            if (n % 10 == 0) return true;
            n /= 10;
        }
        return false;
    };
    };