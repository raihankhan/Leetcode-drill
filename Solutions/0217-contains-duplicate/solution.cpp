class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool>appearedOnce;
        for(int i=0;i<nums.size();i++) {
            if(appearedOnce[nums[i]]) return true;
            appearedOnce[nums[i]]=true;
        }
        return false;
    }
};
