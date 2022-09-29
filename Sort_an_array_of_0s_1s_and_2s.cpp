void sort012(int a[], int n)
    {
        int cntz = 0, cnto = 0, cntt = 0;
        for(int i = 0; i < n; ++i)
        {
            if(a[i] == 0)
            {
                cntz++;
            }
            else if(a[i] == 1)
            {
                cnto++;
            }
            else
            {
                cntt++;
            }
        }
        
        int index = 0, i = 0;
        for(; i < cntz; ++i)
        {
            a[index] = 0;
            index++;
        }
        for(int i = 0; i < cnto; ++i)
        {
            a[index] = 1;
            index++;
        }
        for(int i = 0; i < cntt; ++i)
        {
            a[index] = 2;
            index++;
        }
    }
