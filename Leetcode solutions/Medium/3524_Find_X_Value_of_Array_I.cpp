class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k,0),prevCounts(k,0),curCount(k,0);
        for(int &i:nums) {
            curCount[i%k]++;
            for(long long rem=0;rem<k;rem++)
                curCount[(rem*i)%k]+=prevCounts[rem];
            for(int i=0;i<k;i++)
                result[i]+=curCount[i];
            prevCounts=curCount;
            fill(curCount.begin(),curCount.end(),0);
        }
        return result;
    }
};