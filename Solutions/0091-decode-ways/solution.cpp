class Solution {
public:
    int numDecodings(string s) {
        int len=s.length(),i,j;
        int dp[len+1];
        
        if(s[0]=='0') return 0;
        dp[0]=1,dp[1]=1;
        
        for(int i=2;i<=len;i++)
        {
           dp[i]=0;
           if(s[i-1]!='0')
               dp[i]+=dp[i-1];
           if(s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<'7'))
               dp[i]+=dp[i-2];
        }
        
        return dp[len];
    }
};
