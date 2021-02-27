class Solution {
public:
    int countHomogenous(string s) {
        int mod=1e9+7;
        long long int curr=0;
        long long int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(i==0) curr++;
            else 
            {
                if(s[i]==s[i-1]) curr++;
                else
                {
                    ans=ans+(1LL*curr*(curr+1))/2;
                    ans%=mod;
                    curr=1;
                }
            }
        }
        
        if(curr)
            ans+=(curr*(curr+1))>>1;
            ans%=mod;
        
        return int(ans);
    }
};
