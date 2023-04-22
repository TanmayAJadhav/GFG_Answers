class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        map<long long, long long>mp;
        for(auto num:arr)
        {
            mp[num]++;
        }
        
        long long prev = 0;
        for(auto &it:mp)
        {
            long long freq = it.second;
            it.second = prev;  
            prev = prev + (it.first*freq);
        }
        
        vector<long long>ans(n);
        
        for(int i = 0; i < n; i++)
        {
            ans[i] = mp[arr[i]];
        }
        return ans;
        
    }
};