#include <bits/stdc++.h>
using namespace std;


// Memoization **
int solve(int idx,vector<int>& dp,vector<int>& nums)
    {
        if(idx < 0) return 0;
        if(idx == 0)
            dp[idx] = nums[idx];

        if(dp[idx] != -1)
            return dp[idx];

        
        int pick = nums[idx] + solve(idx - 2,dp,nums);
        int no_pick = solve(idx - 1,dp,nums);

        dp[idx] = max(pick,no_pick);
        return dp[idx];
    }

// Tabulation **
int rob(vector<int>& nums)
    {
        int n = nums.size();

        // base case **
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        vector<int> dp(n);

        // Bottom Up Appraoch 
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);

        for(int i = 2; i < n; i++)
        {
            int pick = nums[i] + dp[i - 2];
            int no_pick = dp[i - 1];

            dp[i] = max(pick,no_pick);
        }
        
        return dp[n - 1];
    }

// Space Optimization **
int rob(vector<int>& nums)
    {
        int n = nums.size();

        // base case **
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);

        // vector<int> dp(n);

        // Space Optimization Appraoch 
        int x = nums[0];
        int y = max(nums[0],nums[1]);

        for(int i = 2; i < n; i++)
        {
            int pick = nums[i] + x;
            int no_pick = y;

            int z = max(pick,no_pick);
            x = y;
            y = z;
        }
        
        return y;
    }
