class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(),logs.end(),[](auto &l,auto &r){return l[1]<r[1];});
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++)
            q.emplace_back(queries[i],i);
        sort(q.begin(),q.end());
        vector<int> result(q.size());
        unordered_map<int,int> count;
        for(int i=0,start=0,end=0;i<q.size();i++) {
            while(start<logs.size()&&logs[start][1]<q[i].first-x)
                if(!--count[logs[start++][0]])
                    count.erase(logs[start-1][0]);
            while(end<logs.size()&&logs[end][1]<=q[i].first)
                if(!++count[logs[end++][0]])
                    count.erase(logs[end-1][0]);
            result[q[i].second]=n-count.size();
        }
        return result;
    }
};