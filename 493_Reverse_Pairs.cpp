class Solution {
public:
    int cnt = 0;
    void conquer(vector<int>&arr, int low, int mid, int high)
    {
        vector<long long>temp;
        int left = low;
        int right = mid+1;
        int x = 0;
        
        int j = mid+1;
        for(int i = low; i <= mid; i++)
        {
            while(j <= high && arr[i] > (2*(long long)arr[j]))
            {
                j++;
            }
            cnt += (j-(mid+1));
        }
        
        while(left <= mid && right <= high)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }
        
        while(left <= mid)
        {
            temp.push_back(arr[left++]);
        }
        
        while(right <= high)
        {
            temp.push_back(arr[right++]);
        }
        
        for(int i = 0, j = low; i < temp.size(); i++,j++)
        {
            arr[j] = temp[i];
        }
    }
    
    void mergesort(vector<int>&arr, int low, int high)
    {
        if(low >= high)
        {
            return;
        }
        
        int mid = low + (high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        
        conquer(arr, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return cnt;
    }
};