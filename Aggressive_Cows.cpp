class Solution {
public:
    
    bool isPossible(int dist, vector<int> &stalls, int k)
    {
        int cntcows = 1, lastcow = stalls[0];
        
        for(int i = 0; i < stalls.size(); i++)
        {
            if(stalls[i] - lastcow >= dist)
            {
                cntcows++;
                lastcow = stalls[i];
            }
            if(cntcows >= k)
            {
                return true;
            }
        }
        
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) 
    {
        int min_ele = *min_element(stalls.begin(),stalls.end());
        int max_ele = *max_element(stalls.begin(),stalls.end());
        
        sort(stalls.begin(),stalls.end());
        int low = 1, high = max_ele-min_ele;
        while(low <= high)
        {
            int mid = (low+high)/2;
            
            if(isPossible(mid,stalls,k))
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return high;
    }
};