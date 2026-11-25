static long MOD=1e11+19,BASE=100003;
class Solution {
public:
    bool hasSingle(vector<int> &s, int l) {
        unordered_map<long,int> hashes;
        long hash=0,pow=1;
        for(int i=0;i<l;i++)
            hash=(hash*BASE+s[i]+1)%MOD;
        for(int i=1;i<l;i++)
            pow=(pow*BASE)%MOD;
        hashes[hash]++;
        for(int i=l;i<s.size();i++) {
            hash=(((hash-pow*(s[i-l]+1))%MOD)+MOD)%MOD;
            hash=(hash*BASE+s[i]+1)%MOD;
            hashes[hash]++;
        }
        for(auto &[k,v]:hashes)
            if(v==1)
                return true;
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int i=1,j=nums.size();
        while(i<j) {
            int mid=i+j>>1;
            if(hasSingle(nums,mid))
                j=mid;
            else
                i=mid+1;
        }
        return i;
    }
};