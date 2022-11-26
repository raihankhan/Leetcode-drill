// Solution with O(n) time and space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int dp[n];
        dp[0]=nums[0];
        if(n>1) dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++) {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};


// Solution with O(n) time and O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev1,prev2;
        prev2=nums[0];
        prev1=max(prev2,nums[1]);
        for(int i=2;i<n;i++) {
            int currPrev1=prev1;
            prev1=max(currPrev1,prev2+nums[i]);
            prev2=currPrev1;
        }
        return prev1;
    }
};