class Solution{
public:
    int maxCoins(int n,vector<vector<int>> &ranges)
    {
        sort(ranges.begin(),ranges.end());
        vector<int>maxtillnow(n,0);
        maxtillnow[n-1] = ranges[n-1][2];
        for(int i = n-2; i >= 0; i--)
        {
            maxtillnow[i] = max(maxtillnow[i+1],ranges[i][2]);
        }
        
        int ans = 0, sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum = ranges[i][2];
            int low = i+1, high = n-1, mid = 0;
            int coins = 0;    
            while(low <= high)
            {
                mid = (high+low)/2;
                if(ranges[mid][0] >= ranges[i][1])
                {
                    high = mid-1;
                    coins = maxtillnow[mid];
                }
                else
                {
                    low = mid+1;
                }
            }
            
            sum += coins;
            ans = max(ans,sum);
        }
        return ans;
        
    }
};