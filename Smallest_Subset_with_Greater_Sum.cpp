class Solution{
    public:
    int minSubset(vector<int> &Arr,int N)
    {
        sort(Arr.rbegin(), Arr.rend());
        long long int tot = 0;
        for(int i = 0; i < N; ++i)
        {
            tot += Arr[i];
        }
        long long int sum = 0;
        for(int i = 0; i < N; ++i)
        {
            sum += Arr[i];
            if(sum > tot-sum)
            {
                return i+1;
            }
        }
        return N;
    }
}