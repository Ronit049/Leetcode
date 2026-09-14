class Solution {
public:
    #define FOR(i,n) for (int i = 0; i < n; i++)



    
    long long solve(long long _n) {
        // count good numbers smaller than n

        string s = to_string(_n);
        int len = (int) s.length();
        long long answer = 0;
        for (int i = 0; i < len; i++) {
            for (int this_digit = 0; this_digit < s[i] - '0'; this_digit++) {
                string t = s;
                t[i] = '0' + this_digit;
                for (int j = i + 1; j < len; j++) {
                    t[j] = '?';
                }
                for (int j = 1; j < len - 1; j++) { // peak or valley position
                    FOR(a,10) FOR(b,10) FOR(c,10) {
                        if ((b > a && b > c) || (b < a && b < c)) {
                            if (t[j-1] != '?' && a != t[j-1] - '0') {
                                continue;
                            }
                            if (t[j] != '?' && b != t[j] - '0') {
                                continue;
                            }
                            if (t[j+1] != '?' && c != t[j+1] - '0') {
                                continue;
                            }
                            bool nonzero = false;
                            for (int k = 0; k < j; k++) {
                                if (t[k] != '0' && t[k] != '?') {
                                    nonzero = true;
                                }
                            }
                            if (a != 0) {
                                nonzero = true;
                            }
                            // t = "0?0?????"
                            long long prefix = 1, suffix = 1;
                            for (int k = 0; k < j - 1; k++) {
                                if (t[k] == '?') {
                                    prefix *= 10;
                                }
                            }
                            for (int k = j + 2; k < len; k++) {
                                if (t[k] == '?') {
                                    suffix *= 10;
                                }
                            }
                            if (!nonzero) {
                                prefix--;
                            }
                            answer += prefix * suffix;
                        }
                    }
                }
            }
        }
        return answer;
    
    }
    long long totalWaviness(long long num1, long long num2) {
        num2++;
        return solve(num2) - solve(num1);
    }
};