// Given two numbers a and b. In one operation you can pick any non negative integer x and either of a or b. Now if you picked a then replace a with a&x else if you picked b then replace b with b&x.Return the minimum number of operation required to make a and b equal.Note: Here & represents bitwise AND operation.

// Example 1:
// Input:
// a = 5, b = 12
// Output:
// 2
// Explanantion:
// In first operation replace 
// a = a&4 = 4
// after that replace 
// b = b&6 = 4
// Hence both are same after applying two
// operations.

class Solution{
  public:
    int solve(int a, int b) {
        int ans = 0;
        while(a!=b)
        {
            int op = a&b;
            if(a<b)
            {
                b=op;
            }
            else
            {
                a=op;
            }
            ans++;
        }
        return ans;
    }
};
