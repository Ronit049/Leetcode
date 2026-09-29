static array<int,501> cnt;
static array<int,1002> sumCount;
class Solution {
public:
    bool hasPairCount(int num) {
        if(sumCount[num])
            return true;
        for(int v=1;v<=500;v++) {
            if(cnt[v]&&v+num<=500&&cnt[v+num]) {
                if(v!=v+num||cnt[v]>=2)
                    return true;
            }
        }
        return false;
    }
    int maxSubarray(vector<int>& nums) {
        cnt.fill(0);
        sumCount.fill(0);
        int result=0;
        for(int i=0,start=0;i<nums.size();i++) {
            while(hasPairCount(nums[i])) {
                cnt[nums[start]]--;
                for(int v=1;v<=500;v++)
                    if(cnt[v])
                        sumCount[v+nums[start]]-=cnt[v];
                start++;
            }
            for(int v=1;v<=500;v++)
                if(cnt[v])
                    sumCount[v+nums[i]]+=cnt[v];
            cnt[nums[i]]++;
            result=max(result,i-start+1);
        }
        return result;
    }
};