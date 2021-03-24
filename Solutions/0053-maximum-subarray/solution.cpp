class Solution {
public:
    int maxSubArray(vector<int>& v) {
        
        int len=v.size();
        
        int dp[len+1];
        dp[0]=v[0];
        
        int last_max=dp[0];
        
        for(int i=1;i<len;i++)
        {
            if(v[i]>v[i]+dp[i-1])
                dp[i]=v[i];
            else dp[i]=v[i]+dp[i-1];
            last_max=max(last_max,dp[i]);
        }
        
        return last_max;
    }
};
