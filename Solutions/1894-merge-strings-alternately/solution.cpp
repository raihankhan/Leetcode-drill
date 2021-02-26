class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int a=0,b=0;
        string ans="";
        while(a<word1.length() and b<word2.length())
        {
            ans+=word1[a];
            ans+=word2[b];
            a++;
            b++;
        }
        
        while(a<word1.length()) ans+=word1[a],a++;
        while(b<word2.length()) ans+=word2[b],b++;
        
        return ans;
    }
};
