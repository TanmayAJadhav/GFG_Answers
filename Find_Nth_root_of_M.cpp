class Solution{
	public:
	
	int helper(int mid, int n, int m)
	{
	    long long mul = 1;
	    
	    for(int i = 1; i <= n; i++)
	    {
	        mul *= mid;
	        if(mul > m)
	        {
	            return 2;
	        }
	    }
	    if(mul == m)
	    {
	        return 1;
	    }
	    return 0;
	}
	
	int NthRoot(int n, int m)
	{
	    int low = 1, high = m;
	    
	    while(low <= high)
	    {
	        int mid = (low+high)/2;
	        int midN = helper(mid,n,m);
	        if(midN==1)
	        {
	            return mid;
	        }
	        else if(midN==0)
	        {
	            low = mid+1;
	        }
	        else
	        {
	            high = mid-1;
	        }
	    }
	    return -1;
	}  
};
