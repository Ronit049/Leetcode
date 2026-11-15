class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        long long result=0;
        stack<int> s;
        vector<int> right(nums.size());
        for(int i=nums.size()-1;i>=0;i--) {
            while(!s.empty()&&nums[s.top()]>nums[i]&&(nums[s.top()]&nums[i])==nums[i])
                s.pop();
            right[i]=s.empty()?nums.size():s.top();
            s.push(i);
        }
        s=stack<int>();
        for(int i=0;i<nums.size();i++) {
            while(!s.empty()&&nums[s.top()]>=nums[i]&&(nums[s.top()]&nums[i])==nums[i])
                s.pop();
            long left=s.empty()?-1:s.top();
            s.push(i);
            result+=(i-left)*(1L*right[i]-i);
        }
        return result;
    }
};