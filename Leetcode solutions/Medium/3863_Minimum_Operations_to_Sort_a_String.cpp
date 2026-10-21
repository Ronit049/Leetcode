class Solution {
public:
    int minOperations(string s) {
        string sorted=s;
        sort(sorted.begin(),sorted.end());
        if(s==sorted)
            return 0;
        if(s.length()==2)
            return -1;
        if(s.front()==sorted.front()||sorted.back()==s.back())
            return 1;
        string temps1=s,temps2=s;
        sort(temps1.begin(),temps1.end()-1);
        sort(temps1.begin()+1,temps1.end());
        sort(temps2.begin()+1,temps2.end());
        sort(temps2.begin(),temps2.end()-1);
        if(temps1==sorted||temps2==sorted)
            return 2;
        return 3;
    }
};