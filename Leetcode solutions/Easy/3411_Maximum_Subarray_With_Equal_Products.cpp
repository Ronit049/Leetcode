class Solution {
public:
    int maxLength(vector<int>& nums) {
        int result=0;
        for(int i=0;i<nums.size();i++) {
            long prod=1,l=nums[i],g=nums[i];
            for(int j=i;j<nums.size();j++) {
                l=lcm(l,nums[j]);
                g=gcd(g,nums[j]);
                prod*=nums[j];
                if(prod>l*g)
                    break;
                if(prod==l*g)
                    result=max(result,j-i+1);
            }
        }
        return result;
    }
};