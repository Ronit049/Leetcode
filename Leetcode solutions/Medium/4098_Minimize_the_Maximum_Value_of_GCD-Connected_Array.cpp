class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)
            return -1;
        int prime=value;
        for(int i=2;i*i<=value;i+=1+(i&1))
            if(value%i==0) {
                prime=i;
                break;
            }
        if(value-prime+2<=2LL*index)
            return -1;
        if(index+1==n)
            return value;
        return value+prime-2+2LL*(n-1-index);
    }
};