class Solution {
public:
    int minOperations(string s) {
        int a=0,b=0;
        int ff=0,ss=1;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]-'0'!=ff) a++;
            if(s[i]-'0'!=ss) b++;
            ff^=1;
            ss^=1;
        }
        
        return min(a,b);
    }
};
