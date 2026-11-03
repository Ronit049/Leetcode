#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
// WARNING: functions as a set (doesn't allow duplicates); insert pairs (ele,idx) instead if duplicates are needed.
// Consider using splay_tree instead if constant factor is an issue (e.g., log^2 solutions), especially with duplicates.
template<typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;  // find_by_order, order_of_key

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int result=0,maxi=0;
        for(int i=0;i+1<nums.size();i++) {
            maxi=max(maxi,nums[i]);
            if(maxi>i+1)
                result+=locked[i]+locked[i+1],locked[i]=locked[i+1]=0;
        }
        if(result>k)
            return -1;
        ordered_set<int> s;
        for(int &i:nums) {
            result+=s.order_of_key(i);
            s.insert(i);
        }
        return result;
    }
};