class Solution {
public:
    int getRes(vector<int> nums,int c) {
        sort(nums.begin(),nums.end());
        if(c==1) {
            nums[0]=nums[(nums.size())/2];
            nums.back()=nums[0];
        } else if(c==2) {
            nums[0]=nums[(nums.size())/2];
            nums[1]=nums[0];
        } else {
            nums.back()=nums[(nums.size())/2];
            nums[nums.size()-2]=nums.back();
        }
        sort(nums.begin(),nums.end());
        return nums.back()-nums.front();
    }
    int minimizeSum(vector<int>& nums) {
        return min({getRes(nums,0),getRes(nums,1),getRes(nums,2)});
    }
};