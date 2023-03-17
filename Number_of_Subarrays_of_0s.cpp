long long int no_of_subarrays(int n, vector<int> &arr) {
    long long int ans = 0;
    long long int cnt_zero = 0;
    for(int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            cnt_zero++;
        }
        else
        {
            ans += ((cnt_zero)*(cnt_zero+1))/2;
            cnt_zero = 0;
        }
    }
    ans += ((cnt_zero)*(cnt_zero+1))/2;
    
    return ans;
}