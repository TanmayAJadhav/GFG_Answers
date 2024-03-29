class Solution {
  public:
    long long int maxSumLCM(int n) 
    {
        long long int sum = 0;
        for(int i = 1; i <= sqrt(n); ++i)
        {
            if(n%i == 0)
            {
                if(n/i == i)
                {
                    sum += i;
                }
                else
                {
                    sum += i + n/i;
                }
            }
        }
        return sum;
    }
};