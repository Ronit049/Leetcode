class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n= s.size();

        unordered_map<string, string> mp;
          
          for(auto &vect :knowledge){
            //vec[0]
            mp[vect[0]] =vect[1];
          }

          string result="";
          int i=0;

          while(i<n){
            if(s[i] =='('){
                int j=s.find(")", i+1);
                string temp=s.substr(i+1, j-i-1);
                result +=mp.count(temp) ? mp[temp] :"?";
                i=j;
            }else{
                result.push_back(s[i]);
            }
            i++;
        }
        return result;
    }
};