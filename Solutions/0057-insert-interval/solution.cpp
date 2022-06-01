class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i;
        for(i=0;i<intervals.size() and intervals[i][1]<newInterval[0];i++) {
            result.push_back(intervals[i]);
        }
        
        int l=newInterval[0] , r=newInterval[1];
        
        if(i<intervals.size()) l=min(l,intervals[i][0]);
        while(i<intervals.size() and r>=intervals[i][0]) {
            r=max(r,intervals[i][1]);
            i++;
        }
        
        result.push_back({l,r});
        
        while(i<intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        
        return result;
    }
};
