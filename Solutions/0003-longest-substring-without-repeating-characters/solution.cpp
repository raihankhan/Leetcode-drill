class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,ans=0;
        bool isPresent[256];
        memset(isPresent,false,sizeof(isPresent));
        while(r<s.length()) {
            if(isPresent[s[r]]) {
                while(s[l]!=s[r]) {
                    isPresent[s[l]]=false;
                    l++;
                }
                isPresent[s[l]]=false;
                l++;
            } else {
                isPresent[s[r]]=true;
                ans = max(ans , r-l+1);
                r++;
            }
        }
        return ans;
    }
};
