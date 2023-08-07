class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {  
        int K = 0;
        map<long long,int>mp;
        int ans = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += A[i];
            if(sum == K)
            {
                ans = max(ans,i+1);
            }
            int rem = sum - K;
            if(mp.find(rem) != mp.end())
            {
                int len = i - mp[rem];
                ans = max(ans,len);    
            }
            
            if(mp.find(sum) == mp.end())
            {
                mp[sum] = i;
            }
        }
        return ans;
    }
// };