class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        if(a.size()==0 || k<=0){
            return {};
        }
        int n=a.size();
        vector<int> result(n-k+1);
        int ri=0;
        deque<int>q;
        for(int i=0;i<n;i++){
            while(!q.empty() && q.front()<i-k+1){
                q.pop_front();
            }
            while(!q.empty() && a[q.back()]<a[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1){
                result[ri++]=a[q.front()];
            }
        }
        return result;
    }
};