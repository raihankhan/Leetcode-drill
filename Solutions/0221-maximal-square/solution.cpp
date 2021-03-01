class Solution {
public:
    int maximalSquare(vector<vector<char>>& m) {
        int len=m.size();
        int dp[301][301]={0};
        int ans=0;
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<m[i].size();j++)
            {
                if(m[i][j]=='1')
                {
                    dp[i+1][j+1]=1+min( dp[i][j], min(dp[i+1][j],dp[i][j+1]) );
                    ans=max(ans,dp[i+1][j+1]);
                }
            }
        }
        
        return ans*ans;
    }
};
