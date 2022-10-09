class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>lastIndex;
        for(int i=0;i<nums.size();i++) {
            if(lastIndex[nums[i]]!=0 && (i-(lastIndex[nums[i]]-1))<=k) { 
               return true; 
            }
            lastIndex[nums[i]]=i+1;
        }
        return false;
    }
};
