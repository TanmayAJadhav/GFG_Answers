class Solution{
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr, arr+n);
	    long long ans = 0, i = 0, j = n-1, k = 0;
	    for(k = 0; k < n-2; k++)
	    {
	        i = k+1;
	        j = n-1;
	        
	        while(i < j)
	        {
	            long long tot = arr[i] + arr[j] + arr[k];
	            if(tot < sum)
	            {
	                ans += (j-i);
	                i++;
	            }
	            else
	            {
	                j--;
	            }
	        }
	    }
	    return ans;
	// }
};