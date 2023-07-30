class Solution{   
public:
    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int,int>mp;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int diff = k - arr[i];
            if(mp[diff])
            {
                ans += mp[diff];
            }
            mp[arr[i]]++;
        }
        return ans;
    }
};
