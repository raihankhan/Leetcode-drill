class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>freq;
        for(int i=0;i<arr.size();i++) {
            freq[arr[i]]++;
        }
        unordered_map<int,bool>occured;
        for(auto i:freq) {
            if(occured[i.second]) {
                return false;
            }
            occured[i.second]=true;
        }
        return true;
    }
};
