class Solution{
public:	
    vector<int>dp;
	int helper(int *arr, int ind)
	{
	    if(ind == 0)
	    {
	        return arr[0];
	    }
	    if(ind < 0)
	    {
	        return 0;
	    }
	    if(dp[ind] != -1)
	    {
	        return dp[ind];
	    }
	    int pick = arr[ind]+helper(arr,ind-2);
	    int notpick = helper(arr,ind-1); 
	    return dp[ind] = max(pick,notpick);
	    
	}
	
	int findMaxSum(int *arr, int n) 
	{
	    dp.resize(n,-1);
	    return helper(arr,n-1);
	}
};
