static int MOD=1e9+7;
template <typename T>
class SegmentTree {
    public:
     SegmentTree(int size) {
        this->size=size;
        // For n=9 segment tree should be able to cover 16 elements, i.e power of 2.
        int height=ceil(log2(size));
        segment_tree.resize((1<<(height+1))-1,{0,UND});
    }
    SegmentTree(vector<int> &nums) {
        if(nums.empty())
            return;
        size=nums.size();
        // For n=9 segment tree should be able to cover 16 elements, i.e power of 2.
        int height=ceil(log2(size));
        segment_tree.resize((1<<(height+1))-1);
        build(nums,0,0,size-1);
    }
    void update(int i,int j,T val) {
        update(0,0,size-1,i,j,val);
    }
    T query(int i, int j) {
        return query(0,0,size-1,i,j);
    }
    private:
    int size;
    T UND=0;
    vector<pair<T,T>> segment_tree;
    /**
    * Push the lazy values to child nodes.
    */
    void pushLazy(int index,int l,int r) {
        int mid=(l+r)/2;
        segment_tree[index*2+1].first+=(mid-l+1)*segment_tree[index].second;
        segment_tree[index*2+1].first%=MOD;
        segment_tree[index*2+1].second+=segment_tree[index].second;
        segment_tree[index*2+1].second%=MOD;
        segment_tree[index*2+2].first+=(r-mid)*segment_tree[index].second;
        segment_tree[index*2+2].first%=MOD;
        segment_tree[index*2+2].second+=segment_tree[index].second;
        segment_tree[index*2+2].second%=MOD;
        segment_tree[index].second=UND;
    }
    /**
    * Build the tree in bottom up fashion.
    */
    void build(vector<int>& nums,int index,int l,int r) {
        if(l==r) {
            segment_tree[index]={nums[l],UND};
            return;
        }
        build(nums,index*2+1,l,(l+r)/2);
        build(nums,index*2+2,(l+r)/2+1,r);
        segment_tree[index]={segment_tree[index*2+1].first+segment_tree[index*2+2].first,UND};
        segment_tree[index].first%=MOD;
    }
    /**
    * Update the tree in bottom up fashion
    */
    void update(int index,int l,int r,int &i,int &j,T &val) {
        // Entire range to update is covered (Update lazy values as well).
        if(r<=j&&l>=i) {
            segment_tree[index]={segment_tree[index].first+val*(r-l+1),segment_tree[index].second+val};
            segment_tree[index].first%=MOD;
            segment_tree[index].second%=MOD;
            return;
        }
        // Segment tree node out of range
        if(r<i||l>j)
            return;
        // Partial range cover (Always push lazy values down when traversing down)
        pushLazy(index,l,r);
        update(index*2+1,l,(l+r)/2,i,j,val);
        update(index*2+2,(l+r)/2+1,r,i,j,val);
        // Since the lazy values are pushed, current node will have no lazy addends.
        segment_tree[index]={segment_tree[index*2+1].first+segment_tree[index*2+2].first,UND};
        segment_tree[index].first%=MOD;
    }
    T query(int index,int l,int r,int &i,int &j){
        // Out of range
        if(l>j||r<i)
            return UND;
        // The range to query covers the entire segment tree's node's range.
        if(i<=l&&j>=r)
            return segment_tree[index].first;
        // Partial range cover (Always push lazy values down when traversing down)
        pushLazy(index,l,r);
        return (query(index*2+1,l,(l+r)/2,i,j)+query(index*2+2,(l+r)/2+1,r,i,j))%MOD;
    }
};
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        SegmentTree<long> st(nums.size());
        unordered_map<int,int> last;
        long result=0,sum=0;
        for(int i=0;i<nums.size();i++) {
            int prev=last.count(nums[i])?last[nums[i]]:-1;
            int pS=st.query(prev+1,i);
            // a^2 + b^2 + c^2 + (d+1)^2 + (e+1)^2 + (f+1)^2
            // = a^2 + b^2 + c^2 + 2(d+e+f) + 3
            sum=((sum+i-prev)%MOD+((2L*pS)%MOD))%MOD;
            st.update(prev+1,i,1);
            // Dp, result for subarrays ending at i.
            result=(result+sum)%MOD;
            last[nums[i]]=i;
        }
        return result;
    }
};