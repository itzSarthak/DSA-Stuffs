#include <bits/stdc++.h>
using namespace std;

long long merge(vector<long long>&nums,long long low,long long mid,long long high)
{
    /*
        This Function Merged Two Sorted Halves as well
        as return inversion count in the two sorted half
    */
    vector<long long>temp;
    long long ans = 0;

    long long i = low;
    long long j = mid + 1;

    while(i <= mid && j <= high)
    {
        if(nums[i] > nums[j])
        {
            temp.push_back(nums[j]);
            ans+=(mid + 1 - i);
            // Why ?
            j++;
        }
        else
        {
            temp.push_back(nums[i]);
            i++;
        }
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

    return ans;
}

// This Function is NOT Required here !!
int countPairs(vector<long long>&nums,int low,int mid,int high)
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

long long solve(vector<long long>&nums,long long  low,long long high)
{
    // 2 5 1 3 4
    long long cnt = 0;
    if(low < high)
    {
        long long cnt = 0;
        long long mid = low + (high - low)/2;

        // Left Half !!
        cnt+= solve(nums,low,mid);

        // Right Half !!
        cnt+= solve(nums,mid + 1,high);

        // Merging Sorted Halves as well as counting pairs if exist !!
        cnt+= merge(nums,low,mid,high);

        return cnt;
    }
    return 0;
}
// Driver Function
int reversePairs(vector<long long>& nums)
{
    return solve(nums,0,nums.size() - 1);
}
int main()
{
    vector<long long>nums{2,5,1,3,4};
    cout<<reversePairs(nums);
    return 0;
}