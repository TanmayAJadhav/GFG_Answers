vector<int> getDistinctDifference(int N, vector<int> &A) 
{
        set<int>s1;
        vector<int>v1(N);
        vector<int>v2(N);
        
        for(int i = 0; i < N; i++)
        {
            v1[i] = s1.size();
            s1.insert(A[i]);
        }
        
        s1.clear();
        
        for(int i = N-1; i >= 0; i--)
        {
            v2[i] = s1.size();
            s1.insert(A[i]);
        }
        
        
        for(int i = 0; i < N; i++)
        {
            v1[i] -= v2[i];
        }
        
        return v1;
}