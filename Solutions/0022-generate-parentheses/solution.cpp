class Solution {
public:
    
    void generator(vector<string>&v, string s, int open, int close , int n) {
   
        if(open==n and close==n) {
            v.push_back(s);
            return;
        }
        
        if(open<n) {
            s.push_back('(');
            generator(v,s,open+1,close,n);
            s.pop_back();
        }
        
        if(close<open) {
            s.push_back(')');
            generator(v,s,open,close+1,n);
            s.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        string s="";
        generator(v,s,0,0,n);
        return v;
    }
};
