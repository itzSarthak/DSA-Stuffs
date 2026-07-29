#include <bits/stdc++.h>
using namespace std;


// Memoization **
// DP : 21
int solve(int idx,int target,vector<int>& nums,vector<vector<int>>& dp)
{
    // base case 
    // target = 0 is not a valid universal base case for the counting version cz it ignores zeros

    // target zero somwhere or we have reached at the end **
    if (idx == 0)
    {
        if(target == 0 && nums[0] == 0)
            return 2;

        if(target == 0 || target == nums[0])
            return 1;

        return 0;
    }

    // already computed ??
    if(dp[idx][target] != -1) return dp[idx][target];

    // otherwise 
    int non_pick = solve(idx - 1,target,nums,dp);

    int pick = 0;
    if(target >= nums[idx])
        pick = solve(idx - 1,target - nums[idx],nums,dp);

    dp[idx][target] = pick + non_pick;
    return dp[idx][target];
}
int findTargetSumWays(vector<int>& nums, int target)
{
    // S2 - S1 = target
    // S2 = (totalSum - target) / 2

    int totalSum = 0;
    for(int i = 0; i < nums.size(); i++)
        totalSum+=nums[i];

    if(totalSum < target || (totalSum - target)%2) return 0;

    target = (totalSum - target)/2;

    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(target + 1,-1));
    return solve(n - 1,target,nums,dp);
}


// Tabulation **
int findTargetSumWays(vector<int>& nums, int target)
{
    // S2 - S1 = target
    // S2 = (totalSum - target) / 2

    int totalSum = 0;
    for(int i = 0; i < nums.size(); i++)
        totalSum+=nums[i];

    if(totalSum < target || (totalSum - target)%2) return 0;

    target = (totalSum - target)/2;

    int n = nums.size();
    vector<vector<int>>dp(n,vector<int>(target + 1,0));


    // base case 
    if(nums[0] == 0)    
        dp[0][0] = 2;
    else 
    {   
        dp[0][0] = 1;
        if(nums[0] <= target) dp[0][nums[0]] = 1;
    }


    for(int idx = 1; idx < n; idx++)
    {
        for(int tg = 0; tg <= target; tg++)
        {
            int non_pick = dp[idx - 1][tg];

            int pick = 0;
            if(tg >= nums[idx])
                pick = dp[idx - 1][tg - nums[idx]];;
                

            dp[idx][tg] = pick + non_pick;
        }
    }

    return dp[n - 1][target];
}