class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto c:s)
        {
            if(c=='(')
                st.push(c);
            else if(c=='{')
                st.push(c);
            else if(c=='[')
                st.push(c);
            else if(c==')')
            {
                if(st.empty()) return false;
                else if(st.top()!='(') return false;
                else st.pop();
            }
            else if(c=='}')
            {
                if(st.empty()) return false;
                else if(st.top()!='{') return false;
                else st.pop();
            }
            else
            {
                if(st.empty()) return false;
                else if(st.top()!='[') return false;
                else st.pop();
            }
        }
        
        if(!st.empty()) return false;
        
        return true;
    }
};
