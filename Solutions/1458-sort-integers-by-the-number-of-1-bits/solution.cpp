class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector< int >cnt[15];
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            int ones=0;
            for(int j=0;j<=14;j++)
            {
                if(arr[i]&(1<<j)) ones++;
            }
            cnt[ones].push_back(arr[i]);
        }
        
        for(int i=0;i<=14;i++)
        {
            sort(cnt[i].begin(),cnt[i].end());
            for(int j=0;j<cnt[i].size();j++) ans.push_back(cnt[i][j]);
        }
        return ans;
    }
};
