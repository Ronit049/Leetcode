static auto cmp=[](auto &l,auto &r){return l[0]*r[1]>l[1]*r[0];};
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        unordered_map<int,int> count,factorCount;
        int maxi=0;
        for(auto &i:items)
            count[i[0]]++;
        for(auto &[key,val]:count)
            for(int i=key;i<=items.size();i+=key)
                if(count.count(i))
                    factorCount[key]+=count[i];
        priority_queue<array<int,3>,vector<array<int,3>>,decltype(cmp)> pq(cmp);
        for(auto &i:items)
            if(factorCount[i[0]]==1)
                pq.push({i[1],1,0});
            else
                pq.push({i[1],min(2,factorCount[i[0]]),factorCount[i[0]]-1});
        int result=0;
        while(budget&&!pq.empty()) {
            auto ele=pq.top();
            int price=ele[0],count=ele[1],total=ele[2];
            pq.pop();
            if(!total) {
                result+=budget/price;
                break;
            }
            else if(price<=budget) {
                int c=min(total,budget/price);
                result+=c*2,pq.push({price,1,0}),budget-=c*price;
            }
        }
        return result;
    }
};