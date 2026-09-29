class Solution {
public:
    long long maxEarnings(vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end(),[](auto &l,auto &r){return l[1]<r[1];});
        long long result=0,maxi=LLONG_MIN;
        map<int,long long> memo;
        for(int i=0;i<meetings.size();) {
            int j=i;
            long long localMaxi=LLONG_MIN;
            while(j<meetings.size()&&meetings[i][1]==meetings[j][1]) {
                int s=meetings[j][0],e=meetings[j][1],r=meetings[j][2];
                auto it=memo.upper_bound(s);
                long long cur=r;
                if(it!=memo.begin())
                    cur=max(cur,r+s+prev(it)->second);
                result=max(result,cur);
                localMaxi=max(localMaxi,cur-e);
                j++;
            }
            maxi=max(maxi,localMaxi);
            memo[meetings[i][1]]=maxi;
            i=j;
        }
        return result;
    }
};