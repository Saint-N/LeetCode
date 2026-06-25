#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen( 256, -1);
        int maxLength = 0;
        int left = 0;

        for( int right = 0; right < s.length(); ++right){
            char currChar = s[right];

            if (lastSeen[currChar] >= left){
                left = lastSeen[currChar] + 1;
            }

            lastSeen[currChar] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;

    }
};
