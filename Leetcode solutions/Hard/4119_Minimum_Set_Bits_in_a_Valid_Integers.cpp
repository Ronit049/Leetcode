class Solution {
public:
    int windowCount,best,MAX_BITS=1;
    vector<int> ands;
    unordered_map<string,int> memo;
    int dp(int start,int bitvec) {
        int bitCount=__builtin_popcount(bitvec);
        if(bitCount>=best)
            return INT_MAX/2;
        if(start==ands.size()) {
            best=bitCount;
            return 0;
        }
        if(ands[start]&bitvec)
            return dp(start+1,bitvec);
        string key=to_string(start)+","+to_string(bitvec);
        if(memo.count(key))
            return memo[key];
        int result=INT_MAX/2;
        for(int bit=0,mask=1;bit<MAX_BITS;bit++,mask<<=1) {
            if(!(ands[start]&mask))
                continue;
            result=min(result,!(bitvec&mask)+dp(start+1,bitvec|mask));
        }
        return memo[key]=result;
    }
    int minSetBits(vector<int>& nums, int k) {
        int maxi=*max_element(nums.begin(),nums.end());
        MAX_BITS=!maxi?1:32-__builtin_clz(maxi);
        best=MAX_BITS+1;
        vector<int> lastZeroBit(MAX_BITS,-1);
        for(int i=0,start=0;i<nums.size();i++) {
            for(int bit=0,mask=1;bit<MAX_BITS;bit++,mask<<=1)
                if(!(nums[i]&mask))
                    lastZeroBit[bit]=i;
            if(i>=k-1) {
                int andVal=0;
                for(int bit=0,mask=1;bit<MAX_BITS;bit++,mask<<=1)
                    if(lastZeroBit[bit]<start)
                        andVal|=mask;
                if(!andVal)
                    return -1;
                ands.push_back(andVal);
                start++;
            }
        }
        return dp(0,0);
    }
};