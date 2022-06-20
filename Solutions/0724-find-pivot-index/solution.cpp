class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for(int i=1;i<n;i++) {
            nums[i]+=nums[i-1];
        }
        sum = nums[n-1];
        if(sum-nums[0]==0) return 0;
        for(int i=1;i<n;i++) {
            if(nums[i-1]==sum-nums[i]) return i;
        }
        return -1;
    }
};
