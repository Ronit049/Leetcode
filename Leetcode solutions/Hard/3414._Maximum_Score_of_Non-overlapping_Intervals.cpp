class Solution {
public:
    vector<vector<pair<long,array<int,4>>>> memo;
    pair<long,array<int,4>> dp(vector<vector<int>>& intervals,int i,int k) {
        if(!k||i==intervals.size())
            return {0,{100000,100000,100000,100000}};
        if(memo[i][k].first!=-1)
            return memo[i][k];
        pair<long,array<int,4>> l=dp(intervals,i+1,k);
        int next=upper_bound(intervals.begin()+i+1,intervals.end(),intervals[i][1],[](const int &x,auto &val){return x<val[0];})-intervals.begin();
        pair<long,array<int,4>> r=dp(intervals,next,k-1);
        r.first+=intervals[i][2];
        r.second[4-k]=intervals[i][3];
        if(r.first>l.first)
            return memo[i][k]=r;
        else if(r.first==l.first) {
            array<int,4> tempL=l.second,tempR=r.second;
            sort(tempL.begin(),tempL.end());
            sort(tempR.begin(),tempR.end());
            if(tempL<tempR)
                return memo[i][k]=l;
            return memo[i][k]=r;
        } else return memo[i][k]=l;
    }
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        memo.resize(intervals.size()+1,vector<pair<long,array<int,4>>>(5,{-1,{}}));
        for(int i=0;i<intervals.size();i++)
            intervals[i].push_back(i);
        sort(intervals.begin(),intervals.end());
        pair<long,array<int,4>> temp=dp(intervals,0,4);
        vector<int> result;
        for(auto &i:temp.second)
            if(i!=100000)
                result.push_back(i);
        sort(result.begin(),result.end());
        return result;
    }
};