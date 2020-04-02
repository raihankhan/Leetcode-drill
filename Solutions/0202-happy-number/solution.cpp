class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool>mm;
        
        bool happy=1;
        int m,sum,p;
        
        while(n>1)
        {
            if(mm[n]) break;
            mm[n]=1;
            
            m=n;
            sum=0;
            while(m)
            {
                p=(m%10);
                sum+=(p*p);
                m/=10;
            }
            
            n=sum;
        }
        
        if(n!=1) happy=0;
        
        return happy;
        
    }
};
