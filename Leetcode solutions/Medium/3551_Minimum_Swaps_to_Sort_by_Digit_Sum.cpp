class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> ns(nums);
        sort(ns.begin(),ns.end(),[](auto& l,auto& r) {
            int sumL=0,sumR=0,left=l,right=r;
            while(left)
                sumL+=left%10,left/=10;
            while(right)
                sumR+=right%10,right/=10;
            return sumL==sumR?l<r:sumL<sumR;
        });
        unordered_map<int,int> idx;
        for(int i=0;i<nums.size();i++)
            idx[nums[i]]=i;
        int result=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=ns[i]) {
                swap(nums[i],nums[idx[ns[i]]]);
                idx[nums[idx[ns[i]]]]=idx[ns[i]];
                idx[nums[i]]=i;
                result++;
            }
        }
        return result;
    }
};