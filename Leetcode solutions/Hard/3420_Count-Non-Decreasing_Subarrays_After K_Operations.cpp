// O(nlog^2(n))
class SparseTable {
    vector<vector<int>> spTable;
    vector<vector<long long>> cost;
    public:
    SparseTable(){}
    long long query(int l,int r) {
        int len=r-l+1,shift=0,currLen=1;
        long long result=0;
        for(int shift=spTable[l].size()-1;shift>=0;shift--)
            if(spTable[l][shift]<=r)
                result+=cost[l][shift],l=spTable[l][shift];
        if(l<=r)
            result+=(r-l+1)*(cost[l][0]/(spTable[l][0]-l));
        return result;
    }
    SparseTable(vector<int> &nums) {
        int logn=ceil(log2(nums.size()));
        spTable.resize(nums.size()+1,vector<int>(logn+1,nums.size()));
        cost.resize(nums.size()+1,vector<long long>(logn+1));
        stack<int> s;
        for(int i=0;i<nums.size();i++) {
            while(!s.empty()&&nums[i]>nums[s.top()])
                spTable[s.top()][0]=i,cost[s.top()][0]=1LL*(i-s.top())*nums[s.top()],s.pop();
            s.push(i);
        }
        while(!s.empty()) {
            cost[s.top()][0]=1LL*(nums.size()-s.top())*nums[s.top()];
            s.pop();
        }
        for(int j=1,sz=2;j<=logn;j++,sz<<=1)
            for(int i=0;i+sz<=nums.size();i++) {
                if(spTable[i][j-1]==nums.size()) {
                    spTable[i][j]=nums.size();
                    cost[i][j]=cost[i][j-1];
                } else {
                    spTable[i][j]=spTable[spTable[i][j-1]][j-1];
                    cost[i][j]=cost[i][j-1]+cost[spTable[i][j-1]][j-1];
                }
            }
    }
};
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        SparseTable sp(nums);
        vector<long long> prefixSum={0};
        long long result=0;
        for(int &i:nums)
            prefixSum.push_back(prefixSum.back()+i);
        for(int start=0;start<nums.size();start++) {
            int i=start,j=nums.size();
            while(i<j) {
                int mid=i+j>>1;
                if(sp.query(start,mid)-prefixSum[mid+1]+prefixSum[start]<=k)
                    i=mid+1;
                else
                    j=mid;
            }
            result+=i-start;
        }
        return result;
    }
};