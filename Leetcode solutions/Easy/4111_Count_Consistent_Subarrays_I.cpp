class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++) {
            int mini=INT_MAX,a=nums[i];
            for(int j=i;j<nums.size();j++) {
                mini=min(mini,nums[j]);
                a&=nums[j];
                result+=a==mini;
            }
        }
        return result;
    }
};