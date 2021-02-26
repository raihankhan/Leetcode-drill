class Solution {
public:
    int dp[1007][2][1007];
    bool vis[1007][2][1007];
    int solve(int i,int mode,int l,int r,vector<int>&nums, vector<int>&muls)
    {
        if(i+1==muls.size())
        {
            if(mode)
                return nums[r]*muls[i];
            else return nums[l]*muls[i];
        }
        int p=(mode==0)?l:nums.size()-r-1;
        int &res = dp[i][mode][p];
        if(vis[i][mode][p]) return res;
        vis[i][mode][p]=1;
        
        int ret=INT_MIN;
        if(mode==0)
        {
            ret=max(ret , muls[i]*nums[l] + solve(i+1,0,l+1,r,nums,muls) );
            ret=max(ret , muls[i]*nums[l] + solve(i+1,1,l+1,r,nums,muls) );
        }
        else
        {
            ret=max(ret , muls[i]*nums[r] + solve(i+1,0,l,r-1,nums,muls) );
            ret=max(ret , muls[i]*nums[r] + solve(i+1,1,l,r-1,nums,muls) );
        }
        
        return res=ret;
    }
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        int l=0,r=nums.size()-1;
        int ans = max( solve(0,0,l,r,nums,muls), solve(0,1,l,r,nums,muls) )   ;
        
        return ans;
    }
};
