class Solution {
public:
    int numSquares(int n) {
        vector<int>sk;
        for(int i=1;i*i<=n;i++)
        {
            sk.push_back(i*i);
        }
        
        int dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=INT_MAX;
            for(int j=0;j<sk.size();j++)
            {
                if(i-sk[j]<0) break;
                if(dp[i-sk[j]]!=INT_MAX)
                {
                    dp[i]=min(dp[i],1+dp[i-sk[j]]);
                }
            }
        }
        
        return dp[n];
    }
};
