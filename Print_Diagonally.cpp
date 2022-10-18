class Solution{
	
	public:
	vector<int> downwardDigonal(int N, vector<vector<int>> A)
	{
	    vector<int>ans;
		for(int i = 0; i < N; ++i)
		{
    	    int tempj = i;
		    for(int j = 0; j <= i; ++j)
		    {
		        ans.push_back(A[j][tempj]);
		        tempj--;
		    }
		}
		
		for(int i = 1; i < N; ++i)
		{
    	    int tempj = N-1;
		    for(int j = i; j < N; ++j)
		    {
		        ans.push_back(A[j][tempj]);
		        tempj--;
		    }
		}
		
		
		return ans;
	}

};