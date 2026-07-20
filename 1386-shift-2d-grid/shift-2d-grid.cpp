class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        
        // Optimize k if it's larger than the total number of elements
        k = k % total;
        
        // Create an empty result grid with the same dimensions
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                // Convert 2D position (r, c) to a 1D index
                int flat_idx = r * n + c;
                
                // Calculate the new 1D position after shift
                int new_flat_idx = (flat_idx + k) % total;
                
                // Convert the new 1D index back to 2D coordinates
                int new_r = new_flat_idx / n;
                int new_c = new_flat_idx % n;
                
                result[new_r][new_c] = grid[r][c];
            }
        }
        
        return result;
    }
};