class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        stack<array<int,3>> s;
        for(int i=0;i<types.size();i++) {
            if(!s.empty()&&s.top()[0]==types[i]&&s.top()[1]==colors[i])
                s.top()[2]++;
            else
                s.push({types[i],colors[i],1});
            while(!s.empty()&&s.top()[2]==groupSize[s.top()[0]])
                s.pop();
        }
        return s.empty();
    }
};