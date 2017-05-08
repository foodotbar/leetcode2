class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int u = 0, d = n-1, l =0, r = n-1, index=1;
        while (index<=n*n) {
            // up
            for (int col = l; col <= r; col++) matrix[u][col] = index++;
            if (++u > d) break;
            // right
            for (int row = u; row <= d; row++) matrix[row][r] = index++;
            if (--r < l) break;
            // down
            for (int col = r; col >= l; col--) matrix[d][col] = index++;
            if (--d < u) break;
            // left
            for (int row = d; row >= u; row--) matrix[row][l] = index++;
            if (++l > r) break;
        }
        return matrix;
    }
};
