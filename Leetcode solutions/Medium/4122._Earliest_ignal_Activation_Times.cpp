class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &e:edges)
            adjList[e[0]].emplace_back(e[1],e[2]);
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> pq;
        for(auto &[v,delay]:adjList[0])
            pq.emplace(delay,v);
        vector<long long> result(n,-1);
        result[0]=0;
        while(!pq.empty()) {
            auto [time,node]=pq.top();
            pq.pop();
            if(result[node]!=-1)
                continue;
            if(!--requiredSignals[node]) {
                result[node]=time;
                for(auto &[v,delay]:adjList[node])
                    pq.emplace(time+delay,v);
            }
        }
        return result;
    }
};