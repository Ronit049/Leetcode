class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq,busy;
        long currSecond=-1;
        int toAdd=0;
        for(int i=0;i<servers.size();i++)
            pq.push({servers[i],i});
        vector<int> result;
        while(toAdd!=tasks.size()) {
            if(!pq.empty())
                currSecond=toAdd;
            else
                currSecond=busy.top().first;
            while(!busy.empty()&&busy.top().first<=currSecond)
                pq.push({servers[busy.top().second],busy.top().second}),busy.pop();
            while(toAdd<tasks.size()&&!pq.empty()&&toAdd<=currSecond) {
                auto server=pq.top();
                pq.pop();
                busy.push({currSecond+tasks[toAdd],server.second});
                result.push_back(server.second);
                toAdd++;
            }
        }
        return result;
    }
};