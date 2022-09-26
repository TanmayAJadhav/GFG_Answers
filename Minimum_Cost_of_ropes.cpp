// There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost. Given N size array arr[] contains the lengths of the ropes. 
// Example 1:

// Input:
// n = 4
// arr[] = {4, 3, 2, 6}
// Output: 
// 29
// Explanation:
// We can connect the ropes in following ways.1) First connect ropes of lengths 2 and 3.Which makes the array {4, 5, 6}. Cost ofthis operation 2+3 = 5. 
// 2) Now connect ropes of lengths 4 and 5.Which makes the array {9, 6}. Cost ofthis operation 4+5 = 9.3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9+6 =15Total cost for connecting all ropes is 5+ 9 + 15 = 29. This is the optimized costfor connecting ropes. Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3,2 and 10), then connect 10 and 3 (we gettwo rope of 13 and 2). Finally weconnect 13 and 2. Total cost in this wayis 10 + 13 + 15 = 38.

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> minheap;
    for (int i = 0; i < n; ++i)
    {
        minheap.push(arr[i]);
    }

    long long ans = 0, first, second;
    while (minheap.size() != 1)
    {
        first = minheap.top();
        minheap.pop();
        second = minheap.top();
        minheap.pop();
        ans += first + second;
        minheap.push(first + second);
    }

    return ans;
}