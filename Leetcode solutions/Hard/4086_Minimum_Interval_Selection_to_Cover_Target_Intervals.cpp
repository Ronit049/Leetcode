class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        vector<pair<int,int>> ranges;
        sort(targetIntervals.begin(),targetIntervals.end());
        for(auto &t:targetIntervals)
            if(ranges.empty()||ranges.back().second<t[0])
                ranges.push_back({t[0],t[1]});
            else
                ranges.back().second=max(ranges.back().second,t[1]);
        sort(availableIntervals.begin(),availableIntervals.end());
        int i=0,maxEnd=INT_MIN,cur=INT_MIN,result=0;
        for(auto&[s,e]:ranges) {
            while(cur<e) {
                bool isContinuing=cur>=s;
                int start=isContinuing?cur:s;
                while (i<availableIntervals.size()&&availableIntervals[i][0]<=start)
                    maxEnd=max(maxEnd,availableIntervals[i++][1]);
                if(isContinuing&&maxEnd<=cur||!isContinuing&&maxEnd<s)
                    return -1;
                cur=maxEnd;
                result++;
            }
        }
        return result;
    }
};