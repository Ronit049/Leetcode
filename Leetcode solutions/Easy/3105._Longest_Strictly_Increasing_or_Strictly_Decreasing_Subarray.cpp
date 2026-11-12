class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();) {
            int curr=i+1;
            while(curr<nums.size()&&nums[curr]<nums[curr-1])
                curr++;
            result=max(result,curr-i);
            i=curr;
        }
        for(int i=0;i<nums.size();) {
            int curr=i+1;
            while(curr<nums.size()&&nums[curr]>nums[curr-1])
                curr++;
            result=max(result,curr-i);
            i=curr;
        }
        return result;
    }
};