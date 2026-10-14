class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>9*num)
            return "";
        string result;
        for(int i=0;i<num;i++) {
            for(int j=9;j>=0;j--)
                if(j<=sum) {
                    sum-=j;
                    result+=to_string(j);
                    break;
                }
        }
        return result;
    }
};