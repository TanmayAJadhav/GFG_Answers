bool findPair(int arr[], int size, int n){
    unordered_map<int,int>mp;
    
    for(int i = 0; i < size; i++)
    {
        mp[arr[i]]++;
    }
    
    for(int i = 0; i < size; i++)
    {
        if(n==0)
        {
            if(mp[(n+arr[i])] >= 2)
            {
                return true;
            }
        }
        else if(mp[(n+arr[i])])
        {
            return true;
        }
    }
    return false;   
}