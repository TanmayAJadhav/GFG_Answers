class Solution {
public:
    long long caltime(int k, vector<int>& piles)
    {
        long long time = 0;
        for(auto x:piles)
        {
            time += ceil((double)x/k);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = *max_element(piles.begin(),piles.end());

        int low = 1, high = n;
        while(low <= high)
        {
            int mid = (low + high)/2;
            if(caltime(mid,piles) <= h)
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        return low;   
    }
};