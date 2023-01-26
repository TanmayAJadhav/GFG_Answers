// Given a string S consisting of only uppercase and lowercase characters. The task is to sort uppercase and lowercase letters separately such that if the ith place in the original string had an Uppercase character then it should not have a lowercase character after being sorted and vice versa.

// Example 1:
// Input:
// N = 12
// S = defRTSersUXI
// Output: deeIRSfrsTUX
// Explanation: Sorted form of given string
// with the same case of character as that
// in original string is deeIRSfrsTUX

// Example 2:
// Input:
// N = 6
// S = srbDKi
// Output: birDKs
// Explanation: Sorted form of given string
// with the same case of character will
// result in output as birDKs.

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string copy(str);
        sort(copy.begin(),copy.end());
        int i = 0,j = 0;
        for(j = 0; j < copy.size(); ++j)
        {
            if(copy[j] >= 'a' && copy[j] <= 'z')
            {
                break;
            }
        }
        
        int k = 0;
        for(k = 0; k < str.size(); ++k)
        {
            if(str[k] >= 'a' && str[k] <= 'z')
            {
                str[k] = copy[j];
                j++;
            }
            else
            {
                str[k] = copy[i];
                i++;
            }
        }
        
        return str;
    }
};