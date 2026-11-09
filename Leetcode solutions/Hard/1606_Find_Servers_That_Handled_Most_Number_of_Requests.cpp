class Solution {
public:
    set<int> freeServers;
    map<int,vector<int>> endTimeServers;
    map<int,vector<int>>::iterator it;
    void loadFreeServers(int arrivalTime)
    {
        it=endTimeServers.upper_bound(arrivalTime);
        for(auto it1=endTimeServers.begin();it1!=it;it1++)
            for(int &i:it1->second)
                freeServers.insert(i);
        endTimeServers.erase(endTimeServers.begin(),it);
    }
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load)
    {

        vector<int> serverTimes(k,0);
        vector<int> result;
        set<int>::iterator it;
        for(int i=0;i<k;i++)
            freeServers.insert(i);
        for(int i=0;i<arrival.size();i++)
        {
            loadFreeServers(arrival[i]);
            if(freeServers.count(i%k))
            {
                freeServers.erase(i%k);
                endTimeServers[arrival[i]+load[i]].push_back(i%k);
                serverTimes[i%k]++;
            }
            else if(!freeServers.empty())
            {
                it=freeServers.lower_bound(i%k);
                if(it!=freeServers.end())
                {
                    endTimeServers[arrival[i]+load[i]].push_back(*it);
                    serverTimes[*it]++;
                    freeServers.erase(*it);
                }
                else
                {
                    endTimeServers[arrival[i]+load[i]].push_back(*freeServers.begin());
                    serverTimes[*freeServers.begin()]++;
                    freeServers.erase(*freeServers.begin());
                }
            }
        }
        int maxTimes=*max_element(serverTimes.begin(),serverTimes.end());
        for(int i=0;i<serverTimes.size();i++)
            if(serverTimes[i]==maxTimes)
                result.push_back(i);
        return result;
    }
};