class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) 
    {
        unordered_map<int,int> prefixSumIndex={{0,-1}};
        int sum=0,result=100001,lLength=100001;
        for(int i=0;i<arr.size();i++)
            sum+=arr[i],prefixSumIndex[sum]=i;
        sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(prefixSumIndex.count(sum-target))
                lLength=min(lLength,i-prefixSumIndex[sum-target]);
            if(prefixSumIndex.count(sum+target))
                result=min(result,lLength+prefixSumIndex[sum+target]-i);
            
        }
        return result==100001?-1:result;
        
    }
};