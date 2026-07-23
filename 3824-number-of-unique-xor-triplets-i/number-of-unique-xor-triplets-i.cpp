class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 1) return 1;
        if (n == 2) return 2;
        
        int power_of_2 = 1;
        while (power_of_2 <= n) {
            power_of_2 <<= 1;
        }
        
        return power_of_2;
    }
};