class Solution {
public:
    vector<int> minOperations(string boxes) {
        int l=0,r=0,total=0;
        int len=boxes.size();
        vector<int>ans(len);
        for(int i=0;i<len;i++)
        {
            if(boxes[i]=='1') total+=i,r++;
        }
        
        if(boxes[0]=='1') r--,l++;
        
        ans[0]=total;
        
        for(int i=1;i<len;i++)
        {
            total=total-r+l;
            ans[i]=total;
            if(boxes[i]=='1') l++,r--;
        }
        
       return ans; 
        
    }
};
