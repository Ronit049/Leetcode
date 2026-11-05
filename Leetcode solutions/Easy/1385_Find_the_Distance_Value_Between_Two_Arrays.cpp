class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int result=0;
        for(int &i:arr1) {
            auto it=lower_bound(arr2.begin(),arr2.end(),i-d);
            result+=it==arr2.end()||*it>d+i;
        }
        return result;
    }
};