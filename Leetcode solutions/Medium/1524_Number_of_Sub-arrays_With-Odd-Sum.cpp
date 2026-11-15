static int MOD=1e9+7;
static int mods[2];
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) 
    {
        memset(mods,0,sizeof mods);
        int result=0;
        bool sum=0;
        mods[0]=1;
        for(int &i:arr)
        {
            sum^=i&1;
            result=(result+mods[!(sum%2)])%MOD;
            mods[sum%2]++;
        }
        return result;
    }
};