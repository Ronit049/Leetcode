static array<int,100001> diffCount;
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        for(int i=0;i<nums1.size();i++)
            diff.push_back(abs(nums1[i]-nums2[i]));
        diffCount.fill(0);
        int maxi=0,total=k1+k2;
        for(int &i:diff)
            maxi=max(maxi,i),diffCount[i]++;
        for(int i=maxi;i>0&&total;i--) {
            int toRemove=min(total,diffCount[i]);
            total-=toRemove;
            diffCount[i]-=toRemove;
            diffCount[i-1]+=toRemove;
        }
        long result=0;
        for(int i=maxi;i>0;i--)
            result+=1L*diffCount[i]*i*i;
        return result;
    }
};