class Solution {
public:
    vector<vector<int>> adjList;
    long dfs(vector<int>& op, vector<int>& score,int node,int parent) {
        if(adjList[node].empty())
            return score[node];
        long result=score[node],mini=LONG_MAX;
        for(int &n:adjList[node])
            if(n!=parent) {
                long cur=dfs(op,score,n,node);
                result+=cur;
                mini=min(mini,cur);
            }
        if(op[node])
            result-=mini;
        else
            result-=min(0L,mini);
        return result;            
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        adjList.resize(parent.size());
        for(int i=1;i<parent.size();i++)
            adjList[parent[i]].push_back(i);
        return dfs(op,score,0,-1);
    }
};