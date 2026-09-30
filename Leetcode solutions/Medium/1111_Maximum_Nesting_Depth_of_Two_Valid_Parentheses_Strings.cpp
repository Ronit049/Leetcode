class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) 
    {
        int depth=0;
        vector<int> result;
        for(char &c:seq)
            result.push_back((c=='('?depth++:--depth)&1);
        return result;
                
    }
};