class Solution {
public:
    int sumDigits(int num) {
        int result=0;
        while(num)
            result+=num%10,num/=10;
        return result;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            if(sumDigits(nums[i])==i)
                return i;
        }
        return -1;
    }
};