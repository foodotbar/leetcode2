class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=(int)obstacleGrid.size();
        int col=(int)obstacleGrid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,0));
        dp[0][0]=obstacleGrid[0][0]==0?1:0;
        for(int i=1;i<col;i++)
            if(obstacleGrid[0][i]==0&&dp[0][i-1])
                dp[0][i]=1;
        for(int j=1;j<row;j++)
            if(obstacleGrid[j][0]==0&&dp[j-1][0])
                dp[j][0]=1;
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++)
                if(obstacleGrid[i][j]==0)
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else
                    dp[i][j]=0;
        }
        return dp[row-1][col-1];
    }
};
