class Solution {
public:
    int countCommas(int n) {
        int cnt=0;
        while(n>0){
            if(n-1000 >=0){
                 cnt+= n-999;
            }
            n=n/1000;
        }
        return cnt;
    }
};