class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int,int> memo;
        sort(nums.begin(),nums.end());
        int result=0;
        for(int &i:nums) {
            memo[i+1]=memo[i]+1;
            memo[i]=memo[i-1]+1;
            result=max(result,max(memo[i],memo[i+1]));
        }
        return result;
    }
};