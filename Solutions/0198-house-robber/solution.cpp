class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0;
        int dp[len+2];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        if(len>1) dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        
        return dp[len-1];
    }
};
