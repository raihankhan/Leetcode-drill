class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        int dp[m+1][n+1];
        bool stop=0;
        for(int i=0;i<m;i++)
        {
            if(obstacleGrid[i][0]) stop=1;
            if(stop) dp[i][0]=0;
            else dp[i][0]=1;
        }
        stop=0;
        for(int j=0;j<n;j++)
        {
            if(obstacleGrid[0][j]) stop=1;
            if(stop) dp[0][j]=0;
            else dp[0][j]=1;
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 or j==0)
                {
                    dp[i][j]=1;
                }
                else
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
    }
};
