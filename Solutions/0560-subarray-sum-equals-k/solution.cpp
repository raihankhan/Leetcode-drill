class Solution {
public:
    int subarraySum(vector<int>& A, int B)
{

    unordered_map<int,int> mm ;

    int sz=A.size(),i,currsum=0,tot=0;

    for(i=0; i<sz; i++)
    {
        currsum+=A[i];

        if(mm.find(currsum-B)!=mm.end())
            tot+=mm[currsum-B];

        mm[currsum]++;
        if(mm.find(currsum)->first==B)
            tot++;
    }
    return tot;
}
};
