class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        for(int i=0,j=0;i<strs[0].length();i++,j++)
        {
            if(strs[0][i]!=strs[strs.size()-1][j])
                return strs[0].substr(0,i);
        }
        return strs[0];
    }
};
