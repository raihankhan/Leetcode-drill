class Solution {
public:
    int countSubstrings(string s) {
        int len=s.length();
        int dp[len+2][len+2];
        memset(dp,0,sizeof(dp));
        
        int total=0;
        for(int i=0;i<len;i++) dp[i][i]=1,total++;
        
        for(int k=2;k<=len;k++)
        {
            for(int i=0;i<len-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j] and i+1==j)
                {
                    dp[i][j]=1;
                    total++;
                    continue;    
                }
                if(s[i]==s[j] and dp[i+1][j-1]==1)
                    dp[i][j]=1,total++;
                else dp[i][j]=0;
            }
        }
        return total;
    }
};
