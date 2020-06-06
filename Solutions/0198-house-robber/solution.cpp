class Solution {
public:
    int rob(vector<int>& nums) {
        int i=0,n=nums.size();
        int dp[102]={0};
        if(n>=1) dp[0]=nums[0];
        if(n>=2) dp[1]=max(dp[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        if(n)
        return dp[n-1];
        else return 0;
    }
};
