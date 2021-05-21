class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        unsigned int dp[1005];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i-nums[j]>=0) dp[i]+=dp[i-nums[j]];
            }
        }
        
        return dp[target];
    }
};
