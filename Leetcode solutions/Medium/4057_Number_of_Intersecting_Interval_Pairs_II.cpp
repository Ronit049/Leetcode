class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        long result=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto &i:intervals) {
            while(!pq.empty()&&pq.top()<i[0])
                pq.pop();
            result+=pq.size();
            pq.push(i[1]);
        }
        return result;
    }
};