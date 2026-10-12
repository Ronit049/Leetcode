static int MOD=1e9+7;
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int result=0;
        vector<int> c(32,0);
        for(int &i:nums)
            for(int j=0,mask=1;j<31;j++,mask<<=1)
                c[j]+=(i&mask)!=0;
        for(int i=0;i<k;i++) {
            long curr=0;
            for(int j=0,mask=1;j<31;j++,mask<<=1)
                if(c[j]) {
                    c[j]--;
                    curr|=mask;
                }
            result=(result+((curr*curr)%MOD))%MOD;
        }
        return result;
    }
};