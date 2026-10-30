static auto cmp=[](auto &l,auto &r){return get<0>(l)>get<0>(r);};
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        priority_queue<tuple<long,int,char,int>,vector<tuple<long,int,char,int>>,decltype(cmp)> pq(cmp);
        vector<vector<pair<int,int>>> adjList(n);
        for(auto &e:edges)
            adjList[e[0]].push_back({e[1],e[2]});
        pq.emplace(0,0,labels[0],1);
        unordered_map<string,long> dist;
        string key="0,"+string(1,labels[0])+",1";
        dist[key]=0;
        while(!pq.empty()) {
            auto [distance,node,character,count]=pq.top();
            key=to_string(node)+","+character+","+to_string(count);
            pq.pop();
            if(dist.count(key)&&dist[key]<distance)
                continue;
            if(node==n-1)
                return distance;
            for(auto &[n,w]:adjList[node]) {
                int newCount=labels[n]==character?count+1:1;
                string newKey=to_string(n)+","+labels[n]+","+to_string(newCount);
                if(newCount<=k&&(!dist.count(newKey)||distance+w<dist[newKey])) {
                    dist[newKey]=distance+w;
                    pq.emplace(distance+w,n,labels[n],newCount);
                }
            }
        }
        return -1;
    }
};