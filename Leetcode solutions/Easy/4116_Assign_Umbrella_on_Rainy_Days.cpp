class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int countA=0,countB=0;
        vector<string> result;
        for(int i=0;i<rain.size();i++) {
            if(rain[i]==1&&i+1<rain.size()&&rain[i+1]==1&&countA<=countB)
                result.push_back("Alice"),countA++;
            else if(rain[i]==1)
                result.push_back("Bob"),countB++;
            else
                result.push_back("None");
        }
        return result;
    }
};