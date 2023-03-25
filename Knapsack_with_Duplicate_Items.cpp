class Solution{
public:
    vector<vector<int>>dp;
    int helper(int ind, int tar, int val[], int wt[])
    {
        if(ind == 0)
        {
            return (tar/wt[ind])*val[ind];
        }
        
        if(dp[ind][tar] != -1)
        {
            return dp[ind][tar];
        }
        
        int nottake = helper(ind-1, tar, val, wt);
        
        int take = INT_MIN;
        
        if(tar >= wt[ind])
        {
            take = val[ind] + helper(ind, tar-wt[ind], val, wt);
        }
        
        return dp[ind][tar] = max(take,nottake);
    }

    int knapSack(int N, int W, int val[], int wt[])
    {
        dp.resize(N,vector<int>(W+1,-1));
        return helper(N-1, W, val, wt);
    }
};