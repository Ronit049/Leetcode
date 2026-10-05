class Solution {
public:
    int f(int a, int b){
        return min(abs(a-b), abs(10-abs(a-b)));
    }
    int minRotations(int n, string s) {
        int sum=f((s[0]-'0'),0);
        for(int i=1; i<n; i++){
            sum+=f((s[i-1]-'0'),(s[i]-'0'));
        }
        int mini=sum;
        for(int k=0; k<n; k++){
            int kyu = (k == 0) ? 0 : s[k-1]-'0';
            int cand = sum + f(kyu, s[n-1]-'0') - f(kyu, s[k]-'0');
            mini=min(mini,cand);
        }
        return mini;
    }
};