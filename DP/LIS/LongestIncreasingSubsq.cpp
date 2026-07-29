#include<bits/stdc++.h>
using namespace std;


// Memoization **
int solve(int idx,int prev_idx,vector<int>& nums,vector<vector<int>>& dp)
{
    if(idx == nums.size()) return 0;

    if(dp[idx][prev_idx + 1] != -1) return dp[idx][prev_idx + 1];

    // not Take
    int l1 = solve(idx + 1,prev_idx,nums,dp);

    // Take
    int l2 = 0;
    if(prev_idx == -1 || nums[idx] > nums[prev_idx])
        l2 = 1 + solve(idx + 1,idx,nums,dp);

    return dp[idx][prev_idx + 1] = max(l1,l2);
}
int lis(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(n + 1,-1));

    return solve(0,-1,nums,dp);
}   

// Tabulation **
int lis(vector<int>& nums)
{
    int n = nums.size();

    // base case covered **
    vector<vector<int>>dp(n,vector<int>(n + 1,0));
    for(int idx = n - 1; idx >= 0; idx--)
    {
        for(int prev_idx = idx - 1; prev_idx >= -1; prev_idx--)
        {
            // not Take -- here prev_idx needs to be shifted since its range (-1 to n - 1)
            // idx is not being shifted we are calculating with the help of ahead value 
            int l1 = dp[idx + 1][prev_idx + 1];

            // Take
            int l2 = 0;
            if(prev_idx == -1 || nums[idx] > nums[prev_idx])
                l2 = 1 + dp[idx + 1][idx + 1];

            return dp[idx][prev_idx + 1] = max(l1,l2);
        }
    }

    return dp[0][0];
}   


// Better Approach **
int lis(vector<int>& nums)
{
    int n = nums.size();
    vector<int>dp(n,1);
    int ans = 1;

    for(int idx = 0; idx < n; idx++)
    {
        for(int prev_idx = 0; prev_idx < idx; prev_idx++)
        {
            if(nums[prev_idx] < nums[idx] && (1 + dp[prev_idx] > dp[idx]))
                dp[idx] = 1 + dp[prev_idx];
        }

        ans = max(ans,dp[idx]);
    }

    // Tc : o(n * n)
    // Sc : o(n)

    return ans;
}   


// LIS Using Binary Search **

// temp = [2, 5, 8]
// means

// some LIS of length 1 ends with 2
// some LIS of length 2 ends with 5
// some LIS of length 3 ends with 8

int lengthOfLIS(vector<int>& nums)
{
    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] > temp.back())
            temp.push_back(nums[i]);

        else
        {
            // this fun return index of nums[i] if present or first idx element greater than it  
            int idx = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }

    return temp.size();
}

// Print LIS
void printlis(vector<int>& nums)
{
    int n = nums.size();
    vector<int>dp(n,1),hash(n);


    int ans = 1;
    int lastIdx = 0;
    for(int idx = 0; idx < n; idx++)
    {
        hash[idx] = idx;
        for(int prev_idx = 0; prev_idx < idx; prev_idx++)
        {
            if(nums[prev_idx] < nums[idx])
            {
                dp[idx] = max(1 + dp[prev_idx],dp[idx]);
                hash[idx] = prev_idx;
                // hash[] stores prev element index that is part of our final subsq **
            }
        }

        // ans stores length of LIS 
        // lastIdx stores index of last element which is part of our LIS **
        if(dp[idx] > ans)
        {
            ans = dp[idx];
            lastIdx = idx;
        }
    }


    // now we have a hash[] and lastIdx 
    vector<int>temp;
    temp.push_back(nums[lastIdx]);

    // this work bcz we initialise hash[] with its own indexes 
    while(hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        temp.push_back(nums[lastIdx]);
    }

    reverse(temp.begin(),temp.end());
    // temp is the answer 
    
}   

int main()
{
    return 0;
}