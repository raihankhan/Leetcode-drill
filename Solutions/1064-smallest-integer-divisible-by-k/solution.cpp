class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int cnt=1,num=1%k;
        int mm[k+1];
        memset(mm,0,sizeof(mm));
        
        while(num!=0)
        {
            if(mm[num]) return -1;
            mm[num]=1;
            num=(num*10+1)%k;
            cnt++;
        }
        return cnt;
    }
};
