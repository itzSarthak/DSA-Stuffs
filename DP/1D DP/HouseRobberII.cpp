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
    int rob(vector<int>& nums)
    {
        int n = nums.size();

        // base case **
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int>arr1,arr2;

        

        for(int i = 0; i < n; i++)
        {
            if(i != 0) arr1.push_back(nums[i]);

            if(i != n - 1) arr2.push_back(nums[i]);
        }

        vector<int>dp1(arr1.size(),-1);
        vector<int>dp2(arr2.size(),-1);

        int first_part = solve(arr1.size() - 1,dp1,arr1);
        int second_part = solve(arr2.size() - 1,dp2,arr2);
        return max(first_part,second_part);
    }

// Space Optimization **
int solve(vector<int>& nums)
    {
        int n = nums.size();

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
    int rob(vector<int>& nums)
    {
        int n = nums.size();
        
        // base case **
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int>arr1,arr2;
        
        // solve two subproblems instead **

        for(int i = 0; i < n; i++)
        {
            if(i != 0) arr1.push_back(nums[i]);

            if(i != n - 1) arr2.push_back(nums[i]);
        }

        int first_part = solve(arr1);
        int second_part = solve(arr2);
        return max(first_part,second_part);
    }
