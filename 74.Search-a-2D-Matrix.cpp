class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        if (target < matrix[0][0] || target > matrix.back().back()) 
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (matrix[mid / n][mid % n] == target) return true;
            else if (matrix[mid / n][mid % n] < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};
