class Solution {
public:
    vector<int> result;
    vector<vector<int>> adjList,newAdjList;
    vector<int> newParent;
    array<int,26> lastChar;
    int dfsSize(int node,int parent) {
        int sz=1;
        for(int &n:newAdjList[node])
            if(n!=parent)
                sz+=dfsSize(n,node);
        result[node]=sz;
        return sz;
    }
    void dfsParent(int node,int parent,string_view s) {
        if(lastChar[s[node]-'a']!=-1)
            newParent[node]=lastChar[s[node]-'a'];
        int prevParent=lastChar[s[node]-'a'];
        for(int &n:adjList[node])
            if(n!=parent) {
                lastChar[s[node]-'a']=node;
                dfsParent(n,node,s);
            }
        lastChar[s[node]-'a']=prevParent;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        newParent.resize(parent.size(),-1);
        result.resize(parent.size(),1);
        adjList.resize(parent.size());
        newAdjList.resize(parent.size());
        lastChar.fill(-1);
        for(int i=1;i<parent.size();i++)
            adjList[parent[i]].push_back(i);
        dfsParent(0,-1,s);
        for(int i=1;i<newParent.size();i++)
            if(newParent[i]==-1)
                newAdjList[parent[i]].push_back(i);
            else
                newAdjList[newParent[i]].push_back(i);
        dfsSize(0,-1);
        return result;
    }
};