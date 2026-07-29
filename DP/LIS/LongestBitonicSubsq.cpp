#include<bits/stdc++.h>
using namespace std;

// longest bitonic subsq can be solved with the help of 
// two dp array that we developed in LIS one normal one and other reverse one (lds)
// combining them for each index will give our answer 

int lbs(vector<int>& nums)
{
    int n = nums.size();

    // dp1[i] stores lis till index i
    vector<int>dp1(n,1);

    for(int idx = 0; idx < n; idx++)
    {
        for(int prev_idx = 0; prev_idx < idx; prev_idx++)
        {
            if(nums[prev_idx] < nums[idx] && 1 + dp1[prev_idx] > dp1[idx])
                dp1[idx] = max(1 + dp1[prev_idx],dp1[idx]);
        }
    }

    // dp2[i] stores lds from i till last **
    vector<int>dp2(n,1);
    int ans = 1;

    for(int idx = n - 1; idx >= 0; idx--)
    {
        for(int prev_idx = n - 1; prev_idx > idx; prev_idx--)
        {
            if(nums[prev_idx] < nums[idx] && 1 + dp2[prev_idx] > dp2[idx])
                dp2[idx] = max(1 + dp2[prev_idx],dp1[idx]);
        }
    }


    int maxi = 0;
    for(int i = 0; i < n; i++)
        maxi = max(maxi,dp1[i] + dp2[i] - 1);

    return maxi;
}  