class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        map<long long,int>mp;
        int ans = 0, sum = 0;
        for(int i = 0; i < N; i++)
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

};
