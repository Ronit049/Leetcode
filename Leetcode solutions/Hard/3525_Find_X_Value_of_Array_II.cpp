template<typename T>
class SegmentTree {
    public:
    SegmentTree(vector<T> &nums, const int k) {
        if(nums.empty())
            return;
        size=nums.size();
        this->k=k;
        UND=Node();
        UND.mod=1;
        // For n=9 segment tree should be able to cover 16 elements, i.e power of 2.
        int height=ceil(log2(size));
        segment_tree.resize((1<<(height+1))-1);
        build(nums,0,0,size-1);
    }
    void update(int index, const T& val) {
        update(0,0,size-1,index,val);
    }
    array<int,5> query(int l, int r) {
        Node result=query(0,0,size-1,l,r);
        return result.remainderCounts;
    }
    private:
    struct Node {
        Node(){}
        Node(const int num,const int k) {
            mod=num%k;
            remainderCounts[mod]++;
        }
        Node merge(const Node& right,const int k) {
            Node result;
            result.mod=(this->mod*right.mod)%k;
            result.remainderCounts=this->remainderCounts;
            for(int i=0;i<remainderCounts.size();i++)
                result.remainderCounts[(i*this->mod)%k]+=right.remainderCounts[i];
            return result;
        }
        int mod=1;
        array<int,5> remainderCounts={0,0,0,0,0};
    };
    int size,k;
    Node UND;
    vector<Node> segment_tree;
    /**
    * Build the tree in bottom up fashion
    */
    void build(vector<T>& nums,int sTIndex,int l,int r) {
        if(l==r) {
            segment_tree[sTIndex]=Node(nums[l],k);
            return;
        }
        build(nums,sTIndex*2+1,l,(l+r)/2),build(nums,sTIndex*2+2,(l+r)/2+1,r);
        segment_tree[sTIndex]=segment_tree[sTIndex*2+1].merge(segment_tree[sTIndex*2+2],k);
    }
    /**
    * Update the tree in bottom up fashion
    */
    void update(int sTIndex,int coveringL,int coveringR,int &index,const T &val) {
        if(coveringL==coveringR&&coveringR==index) {
            segment_tree[sTIndex]=Node(val,k);
            return;
        }
        // If `i` is covered in the range update.
        if(coveringL<=index&&coveringR>=index) {
            update(sTIndex*2+1,coveringL,(coveringL+coveringR)/2,index,val);
            update(sTIndex*2+2,(coveringL+coveringR)/2+1,coveringR,index,val);
            segment_tree[sTIndex]=segment_tree[sTIndex*2+1].merge(segment_tree[sTIndex*2+2],k);
        }
    }
    Node query(int sTIndex,int coveringL,int coveringR,int &l,int &r) {
        // Range does not cover, return `undefined`.
        if(coveringL>r||coveringR<l)
            return UND;
        // Range covers completely.
        if(l<=coveringL&&r>=coveringR)
            return segment_tree[sTIndex];
        // Range covers partially.
        return query(sTIndex*2+1,coveringL,(coveringL+coveringR)/2,l,r).merge(query(sTIndex*2+2,(coveringL+coveringR)/2+1,coveringR,l,r),k);
    }
};
class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree st(nums,k);
        vector<int> result;
        for(auto &q:queries) {
            st.update(q[0],q[1]);
            result.push_back(st.query(q[2],nums.size()-1)[q[3]]);
        }
        return result;
    }
};