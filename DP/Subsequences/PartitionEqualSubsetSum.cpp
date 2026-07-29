#include <bits/stdc++.h>
using namespace std;

// DP : 15
// Problem : Weather this array can be partioned into two such that sum of them are equals
// Since sum of both partioned subsets must be equals it must be equals to half of total sum
// This proble is SubsetSumTarget Problem with target equals total_sum/2 **

// This is a recursive approach and it is working fine 

// Recursive Approach **
bool solve(int idx,int sum1,int sum2,vector<int>& nums)
{
    if(idx < 0)
        return (sum1 == sum2);

    
    // pick for the first subset
    bool left = solve(idx - 1,sum1 + nums[idx],sum2,nums);

    // pick for the second subset
    bool right = solve(idx - 1,sum1,sum2 + nums[idx],nums);

    return left || right;
}
bool canPartition(vector<int>& nums)
{
    return solve(nums.size() - 1,0,0,nums);
}


// Memoization Approach **
bool solve(int idx,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    // base case 

    // target zero somwhere or we have reached at the end **
    if(target == 0) return true;
    if(idx == 0) return (target == arr[0]);

    // already computed ??
    if(dp[idx][target] != -1) return dp[idx][target];

    // otherwise 
    bool non_pick = solve(idx - 1,target,arr,dp);

    bool pick = false;
    if(target >= arr[idx])
        pick = solve(idx - 1,target - arr[idx],arr,dp);

    dp[idx][target] = pick || non_pick;
    return dp[idx][target];
}
bool canPartition(vector<int>& nums)
{
    // Calculate total sum
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
        sum+=nums[i];

    if(sum%2) return false;

    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(sum/2 + 1,-1));
    // note that in dp array rows [0,n-1] & cols [0,target]
    // this means size of dp must be [n * (target + 1)]

    return solve(n - 1,sum/2,nums,dp);
}


// Tabulation **
bool canPartition(vector<int>nums)
{
    int sum = 0;
    for(int i = 0; i < nums.size(); i++)
        sum+=nums[i];

    if(sum%2) return false;

    // what does this dp represents **
    // dp[idx][target] represents weather there exists a subsequences sum till idx (from zero) equals to target **

    int n = nums.size();
    vector<vector<bool>>dp(n,vector<bool>(sum/2 + 1,false));

    // target zero -- case (base)
    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    // index zero -- case (base)
    if(nums[0] <= sum/2)
        dp[0][nums[0]] = true;

    for(int i = 1; i < n; i++)
    {
        for(int tg = 0; tg <= sum/2; tg++)
        {
            // dp[i][sum/2] = dp[i - 1][target] || dp[i - 1][target - nums[i]];

            bool no_pick = dp[i - 1][tg];

            bool pick = false;
            if(tg >= nums[i])
                pick = dp[i - 1][tg - nums[i]];

            dp[i][tg] = pick || no_pick;
        }
    }

    return dp[n - 1][sum/2];
}


int main()
{
    return 0;
}