class Solution {
public:
    pair<int,bool> isSortable(vector<int>& nums,int i,int j) {
        int start=i;
        for(int k=i;k+1<=j;k++)
            if(nums[k]>nums[k+1]) {
                if(start!=i)
                    return {-1,false};
                start=k+1;
            }
        if(start==i)
            return {i,true};
        return {start,nums[j]<=nums[i]};
    }
    bool isKSortable(vector<int>& nums,int k) {
        int prevMax=-1;
        for(int i=0;i<nums.size();i+=k) {
            auto [minIdx,canSort]=isSortable(nums,i,i+k-1);
            if(!canSort||nums[minIdx]<prevMax)
                return false;
            prevMax=nums[minIdx==i?i+k-1:minIdx-1];
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int result=0;
        for(int sz=1;sz*sz<=nums.size();sz++) {
            if(nums.size()%sz==0) {
                if(isKSortable(nums,sz))
                    result+=sz;
                if(sz!=nums.size()/sz&&isKSortable(nums,nums.size()/sz))
                    result+=nums.size()/sz;
            }
        }
        return result;
    }
};class Solution {
public:
    pair<int,bool> isSortable(vector<int>& nums,int i,int j) {
        int start=i;
        for(int k=i;k+1<=j;k++)
            if(nums[k]>nums[k+1]) {
                if(start!=i)
                    return {-1,false};
                start=k+1;
            }
        if(start==i)
            return {i,true};
        return {start,nums[j]<=nums[i]};
    }
    bool isKSortable(vector<int>& nums,int k) {
        int prevMax=-1;
        for(int i=0;i<nums.size();i+=k) {
            auto [minIdx,canSort]=isSortable(nums,i,i+k-1);
            if(!canSort||nums[minIdx]<prevMax)
                return false;
            prevMax=nums[minIdx==i?i+k-1:minIdx-1];
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int result=0;
        for(int sz=1;sz*sz<=nums.size();sz++) {
            if(nums.size()%sz==0) {
                if(isKSortable(nums,sz))
                    result+=sz;
                if(sz!=nums.size()/sz&&isKSortable(nums,nums.size()/sz))
                    result+=nums.size()/sz;
            }
        }
        return result;
    }
};