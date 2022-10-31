class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        //if(r==0) return nums[0];
        while(l<r) {
            mid = (l+r)>>1;
            if(nums[l]<nums[r]) return nums[l];
            else if(nums[mid]>nums[r]) {
                l=mid+1;
            } else {
                r=mid;
            }
        }
        return nums[l];
    }
};
