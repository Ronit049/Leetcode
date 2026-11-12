class Solution {
public:
    unordered_map<int,int> count;
    int diff=0;
    void update(int num,int delta) {
        if(count[num]!=0)
            diff--;
        if((count[num]+=delta)!=0)
            diff++;
    }
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int equal=0,result=0;
        bool isSorted=true;
        for(;equal<nums.size()&&nums[equal]==target[equal];equal++);
        for(int i=nums.size()-1;i>=0;i--) {
            update(nums[i],1);
            update(target[i],-1);
            if(i+1<nums.size()&&target[i]<target[i+1])
                isSorted=false;
            result+=isSorted&&i<=equal&&!diff;
        }
        return result;
    }
};