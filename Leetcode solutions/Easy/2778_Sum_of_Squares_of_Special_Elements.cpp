class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
            result+=(nums.size()%(i+1)==0)?nums[i]*nums[i]:0;
        return result;
    }
};