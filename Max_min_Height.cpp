class Solution
{
    public:
        bool possible(int n,int k,int w,vector <int> a, int middle_height)
        {
            for(int i = 0; i < n; i++)
            {
                if(a[i] < middle_height)
                {
                    int temp = middle_height - a[i];
                    
                    if(temp > k)
                    {
                        return false;
                    }
                    
                    k -= temp;
                    
                    a[i] = middle_height;
                    
                    for(int j = i+1; j < n && j < i+w; j++)
                    {
                        a[j] += temp;
                    }
                }
            }
            return true;
        }
        
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            int min_height = INT_MAX, max_height = 0;
            
            for(int i = 0; i < n; i++)
            {
                min_height = min(min_height,a[i]);
            }
            
            max_height = min_height + k;
            
            long long ans = min_height;
            
            while(min_height <= max_height)
            {
                int middle_height = (min_height+max_height)/2;
                
                if(possible(n,k,w,a,middle_height))
                {
                    ans = middle_height;
                    min_height = middle_height + 1;
                }
                else
                {
                    max_height = middle_height - 1;
                }
            }
            
            return ans;
        }
        
};