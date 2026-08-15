#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>&nums,int low,int mid,int high)
{
    /*
        This Function Merged Two Sorted Halves !
        Remember a single element in an array is always sorted !!
    */
    vector<int>temp;

    int i = low;
    int j = mid + 1;

    while(i <= mid && j <= high)
    {
        if(nums[i] <= nums[j])
            temp.push_back(nums[i++]);

        else
            temp.push_back(nums[j++]);
    }

    // Left Half Remains !!
    while(i <= mid)
    {
        temp.push_back(nums[i]);
        i++;
    }

    // Right Half Remains !!
    while(j <= high)
    {
        temp.push_back(nums[j]);
        j++;
    }

    // Dump all temp to nums !
    for(int i = low; i <= high; i++)
        nums[i] = temp[i - low];
}
int countPairs(vector<int>&nums,int low,int mid,int high)
{
    // This Function is used to find no. of pairs in two sorted halves !!
    int ans = 0;
    int j = mid + 1;

    for(int i = low; i <= mid; i++)
    {
        while(j <= high && nums[i] > 2*nums[j]) j++;

        ans+=(j - (mid + 1));
    }
    return ans;
}
int solve(vector<int>&nums,int low,int high)
{
    if(low < high)
    {
        int cnt = 0;
        int mid = low + (high - low)/2;

        // Left Half !!
        cnt+= solve(nums,low,mid);

        // Right Half !!
        cnt+= solve(nums,mid + 1,high);

        // Finding Pairs in b/w the two halves !!
        cnt+= countPairs(nums,low,mid,high);

        // Merging Sorted Halves !!
        merge(nums,low,mid,high);

        return cnt;
    }
    return 0;
}
// Driver Function
int reversePairs(vector<int>& nums)
{
    return solve(nums,0,nums.size() - 1);
}
int main()
{
    
    return 0;
}