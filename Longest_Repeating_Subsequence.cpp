class Solution {
	public:
		int LongestRepeatingSubsequence(string str)
		{
		    int n = str.size();
		    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
		    
		    for(int i = dp.size()-1; i >= 0; i--)
		    {
		        for(int j = dp.size()-1; j >= 0; j--)
		        {
		            if(i==dp.size()-1 && j == dp[0].size()-1)
		            {
		                dp[i][j] = 0;
		            }
		            else if(i==dp.size()-1)
		            {
		                dp[i][j] = 0;
		            }
		            else if(j == dp[0].size()-1)
		            {
		                dp[i][j] = 0;
		            }
		            else
		            {
    		            if(str[i] == str[j] && i != j)
    		            {
    		                dp[i][j] = 1 + dp[i+1][j+1];
    		            }
    		            else
    		            {
    		                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
    		            }
		            }
		        }
		    }
		    return dp[0][0];
		}

};