class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(),a.end());
        int ans = INT_MAX, i = m-1, j = 0, diff = 0;
        
        while(i < n)
        {
            diff = a[i] - a[j];
            ans = min(ans,diff);
            i++;
            j++;
        }
        
        return ans;
    }   
};
