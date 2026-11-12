class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> result;
        for(int i=0;i<s1.length();) {
            int j=0;
            while(i+j<s1.length()&&s1[i+j]!=s2[i+j])
                j++;
            if(j)
                result.push_back({s1.substr(i,j),s2.substr(i,j)});
            i+=j+1;
        }
        return result;
    }
};