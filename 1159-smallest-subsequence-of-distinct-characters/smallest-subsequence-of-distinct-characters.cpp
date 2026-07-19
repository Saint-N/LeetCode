class Solution {
public:
    string smallestSubsequence(string s) {
        // Step 1: Count the total occurrences of each character
        vector<int> last_occurrence(26, 0);
        for (int i = 0; i < s.length(); i++) {
            last_occurrence[s[i] - 'a'] = i;
        }
        
        // Step 2: Track if a character is already in our result stack
        vector<bool> in_stack(26, false);
        string result = ""; // Using string as our stack
        
        // Step 3: Iterate through the string and build the subsequence
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            
            // If the character is already included, we skip it
            if (in_stack[c - 'a']) {
                continue;
            }
            
            // Greedy choice: pop larger characters if they appear again later
            while (!result.empty() && result.back() > c && last_occurrence[result.back() - 'a'] > i) {
                in_stack[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            // Push the current character into our result
            result.push_back(c);
            in_stack[c - 'a'] = true;
        }
        
        return result;
    }
};