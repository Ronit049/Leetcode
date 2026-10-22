class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(is_sorted(nums.begin(),nums.end()))
           return 0;
        vector<int> idx1,idx2;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]>nums[(i+1)%nums.size()])
                idx1.push_back(i);
            if(idx1.size()>1)
                break;
        }
        int zero=find(nums.begin(),nums.end(),0)-nums.begin();
        if(idx1.size()==1) {
            return min(zero,(int)nums.size()-zero+2);
        }
        for(int i=0;i<nums.size();i++) {
            if(nums[i]<nums[(i+1)%nums.size()])
                idx2.push_back(i);
            if(idx2.size()>1)
                break;
        }
        if(idx2.size()==1) {
            return min(nums.size()-zero,1+(zero+1)%nums.size());
        }
        return -1;
    }
};