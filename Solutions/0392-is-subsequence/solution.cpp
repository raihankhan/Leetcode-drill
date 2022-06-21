class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l=0,r=0;
        
        while(l<s.length() && r<t.length()) {
            if(s[l]==t[r]) {
                l++, r++;
            } else {
                r++;
            }
        }
        
        if(l==s.length()) return true;
        return false;
        
    }
};
