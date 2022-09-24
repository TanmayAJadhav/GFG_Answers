int swapBitGame(long long N)
{
        
    int x, count=0;
    while(N)
    {
        N = N & (N-1);
        count++;
    }
    
    if(count%2==1)
    {
        return 1;
    }
    else
    {
        return 2;
        
    }
}