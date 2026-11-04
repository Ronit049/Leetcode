template<typename T>
class MedianManager {
    public:
    void add(const T num) {
        sorted.insert(num);
        if(sorted.size()==1)
            mid=sorted.begin(),leftSum+=num;
        else {
            if(num>=*mid)
                rightSum+=num;
            else
                leftSum+=num;
            if(sorted.size()%2==0&&num<*mid)
                rightSum+=*mid,leftSum-=*mid--;
            else if((sorted.size()&1)&&num>=*mid)
                mid++,rightSum-=*mid,leftSum+=*mid;
        }
    }
    void remove(const T num) {
        if((sorted.size()&1)&&num>=*mid)
            leftSum-=*mid,rightSum+=*mid--;
        else if(sorted.size()%2==0&&num<=*mid)
            mid++,leftSum+=*mid,rightSum-=*mid;
        if(num<=*mid)
            leftSum-=num;
        else
            rightSum-=num;
        auto it=sorted.find(num);
        if(it==mid)
            mid++,leftSum+=*mid,rightSum-=*mid;
        sorted.erase(it);
    }
    T getMedian() {
        return *mid;
    }
    long long getLeftSum() {
        return leftSum;
    }
    long long getRightSum() {
        return rightSum;
    }
    private:
    long long leftSum=0,rightSum=0;
    multiset<T> sorted;
    multiset<T>::iterator mid;
};
class Solution {
public:
    vector<long long> cost;
    int x;
    vector<vector<long long>> memo;
    long long dp(int i,int k) {
        if(!k)
            return 0;
        if(memo[i][k]!=-1)
            return memo[i][k];
        long long result=cost[i]+dp(i+x,k-1);
        if((k-1)*x+1<cost.size()-i)
            result=min(result,dp(i+1,k));
        return memo[i][k]=result;
    }
    long long minOperations(vector<int>& nums, int x, int k) {
        this->x=x;
        memo.resize(nums.size(),vector<long long>(k+1,-1));
        MedianManager<int> mm;
        for(int i=0;i<nums.size();i++) {
            mm.add(nums[i]);
            if(i>=x) {
                mm.remove(nums[i-x]);
            }
            if(i>=x-1)
                cost.push_back(mm.getMedian()*((x+1)/2LL)-mm.getLeftSum()+mm.getRightSum()-mm.getMedian()*(x/2LL));
        }
        return dp(0,k);
    }
};