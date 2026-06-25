class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; // Handle edge cases 0 and 1
        
        int l = 1; 
        int r = x / 2;
        int res = 0;
        
        while (l <= r) {
            int m = l + ((r - l) / 2); // Avoid subtraction typo and overflow
            
            // Use division to prevent m * m integer overflow
            if (m > x / m) { 
                r = m - 1;
            } else {
                res = m; // m * m <= x, so m is a valid potential floor square root
                l = m + 1;
            }
        }
        return res;
    }
};
