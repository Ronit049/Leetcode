class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long result=LLONG_MIN/2,a=result,b=result,a0=result,b0=result,maxi=result;
        for(long long i:nums) {
            long long na=max(b+i,i),nb=a-i;
            long long na0=b0+i,nb0=a0-i;
            na0=max(na0,a),nb0=max(nb0,b);
            a=na,b=nb,a0=na0,b0=nb0;
            result=max({result,a,b,a0,b0});
        }
        return result;
    }
}; 