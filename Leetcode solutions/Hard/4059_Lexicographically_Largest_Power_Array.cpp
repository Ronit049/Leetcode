class Solution {
public:
    vector<int> result{vector<int>(15,0)};
    array<bool,15> isDone;
    void dfs(const vector<int>& nums,int bitIdx) {
        if(bitIdx==15)
            return;
        if(isDone[bitIdx]) {
            dfs(nums,bitIdx+1);
            return;
        }
        vector<int> withBit,withoutBit;
        int currentBitMask=1<<(14-bitIdx);
        for(int num:nums)
            if(num&currentBitMask)
                withBit.push_back(num);
            else
                withoutBit.push_back(num);
        if(!withBit.empty()) {
            result[bitIdx]+=withBit.size();
            dfs(withBit,bitIdx+1);
        }
        if(!withoutBit.empty()) {
            isDone[bitIdx]=1;
            dfs(withoutBit,bitIdx+1);
        }
    }
    vector<int> largestPower(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
};