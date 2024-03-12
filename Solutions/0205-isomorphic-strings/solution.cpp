class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int i;
        map<char,char> hash,alpha;

        for(i=0;i<s.length();i++) {
            if(hash[t[i]]==NULL) {
                hash[t[i]]=s[i];
            } else if(hash[t[i]]!=s[i]) {
                return false;
            }

            if(alpha[s[i]]==NULL) {
                alpha[s[i]]=t[i];
            } else if(alpha[s[i]]!=t[i]) {
                return false;
            }
        }

        return true;
    }
};
