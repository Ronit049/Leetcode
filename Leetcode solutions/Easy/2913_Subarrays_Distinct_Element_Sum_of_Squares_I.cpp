class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++)
            for(int j=i;j<nums.size();j++) {
                unordered_set<int> s(nums.begin()+i,nums.begin()+j+1);
                result+=s.size()*s.size();
            }
        return result;
    }
};