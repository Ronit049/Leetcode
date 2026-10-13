class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](auto &l,auto &r){return abs(l)<abs(r);});
        long long result=0;
        for(int i=0,j=nums.size()-1;i<=j;i++,j--) {
            if(i<j) {
                result+=1LL*nums[j]*nums[j];
                result-=1LL*nums[i]*nums[i];
            } else {
                result+=1LL*nums[i]*nums[i];
            }
        }
        return result;
    }
};