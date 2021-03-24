class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int dp[len+7];
        int parent[len+7];
        for(int i=0;i<len;i++) dp[i]=1,parent[i]=-1;
        
        int max_sub=0,id=0;
        
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0)
                {
                    if(dp[j]+1>dp[i])
                    {
                        dp[i]=1+dp[j];
                        parent[i]=j;
                    }
                    
                    if(dp[i]>max_sub)
                        max_sub=dp[i], id=i;
                }
            }
        }
        
        vector<int>ret;
        
        while(1)
        {
            if(parent[id]==-1)
            {
                ret.push_back(nums[id]);
                break;
            }
            
            ret.push_back(nums[id]);
            id=parent[id];
            
        }
        
        return ret;
        
        
    }
};
