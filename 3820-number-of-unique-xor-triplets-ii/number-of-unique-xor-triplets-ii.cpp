#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        // Find the maximum value to determine the upper bound power of 2
        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }
        
        int T = 1;
        while (T <= maxVal) {
            T <<= 1;
        }
        
        // s1[x] will be true if x can be formed by nums[i] ^ nums[j]
        vector<bool> s1(T, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                s1[nums[i] ^ nums[j]] = true;
            }
        }
        
        // s2[x] will be true if x can be formed by XORing 3 elements
        vector<bool> s2(T, false);
        for (int x = 0; x < T; ++x) {
            if (s1[x]) {
                for (int num : nums) {
                    s2[x ^ num] = true;
                }
            }
        }
        
        // Count the number of distinct triplet XOR values
        int count = 0;
        for (int i = 0; i < T; ++i) {
            if (s2[i]) {
                count++;
            }
        }
        
        return count;
    }
};