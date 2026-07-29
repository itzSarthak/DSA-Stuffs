#include <bits/stdc++.h>
using namespace std;

// Prob : 1 
// DP : 20
// we are staring from n - 1
// solve(n - 1,amount) - mimimum coins till index n - 1 that gives sum equals amount **
int solve(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp)
{
    // base case :
    if(idx == 0)
    {
        if(amount % coins[0] == 0)
            return amount / coins[0];

        return 1e9;
    }

    // Already Computed
    if(dp[idx][amount] != -1) return dp[idx][amount];
    // dp[idx][amount] represent mimimum coins till index idx that gives sum equals amount

    int no_pick = solve(idx - 1,amount,coins,dp);
    int pick = 1e9;
    if(coins[idx] <= amount)
        pick = 1 + solve(idx,amount - coins[idx],coins,dp);
        // 1 + because here you are finding total no of coins required and then taking min

    return dp[idx][amount] = min(pick,no_pick);
}
int coinChange(vector<int>& coins, int amount)
{
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
    // this stores mimmum total combination of coins which equals amount **
    // dp[i][am] - i is tll idx and am is the amount 

    int ans = solve(n - 1,amount,coins,dp);

    

    if(ans == 1e9) return -1;

    return ans;
}


// Tabulation
int coinChange(vector<int>& coins, int amount)
{
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount + 1,0));


    // base case
    for(int amt = 0; amt <= amount; amt++)
    {
        if(amt % coins[0] == 0)
            dp[0][amt] = amt/coins[0];

        else dp[0][amt] = 1e9;
    }
    

    // otherwise
    for(int idx = 1; idx < n; idx++)
    {
        for(int amt = 0; amt <= amount; amt++)
        {
            int no_pick = dp[idx - 1][amt];
            int pick = 1e9;
            if(coins[idx] <= amt)
                pick = 1 + dp[idx][amt - coins[idx]];

            dp[idx][amt] = min(pick,no_pick);
        }
    }

    int ans = dp[n - 1][amount];
    if(ans == 1e9) return -1;

    return ans;
}


// Prob : 2
// DP : 22
// Here we need to find total combinations 
// Memoization : 
int solve(int idx,int amount,vector<int>& coins,vector<vector<int>>& dp)
    {
        // base case :
        if(idx == 0)
        {
            if(amount % coins[0] == 0)
                return 1;

            return 0;
        }

        // Already Computed
        if(dp[idx][amount] != -1) return dp[idx][amount];
        // dp[idx][amount] represent mimimum coins till index idx that gives sum equals amount

        int no_pick = solve(idx - 1,amount,coins,dp);
        int pick = 0;
        if(coins[idx] <= amount)
            pick = solve(idx,amount - coins[idx],coins,dp);

        return dp[idx][amount] = pick + no_pick;
    }
int change(int amount, vector<int>& coins)
{
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount + 1,-1));
    // this stores total combination of coins which equals amount **

    int ans = solve(n - 1,amount,coins,dp);
    return ans;
}


// Tabulation **
int change(int amount, vector<int>& coins)
{
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount + 1,0));


    // base case
    for(int amt = 0; amt <= amount; amt++)
    {
        if(amt % coins[0] == 0)
            dp[0][amt] = 1;
    }


    // otherwise
    for(int idx = 1; idx < n; idx++)
    {
        for(int amt = 0; amt <= amount; amt++)
        {
            long long no_pick = dp[idx - 1][amt];
            long long pick = 0;
            if(coins[idx] <= amt)
                pick = dp[idx][amt - coins[idx]];

            dp[idx][amt] = pick + no_pick;
        }
    }

    int ans = dp[n - 1][amount];
    return ans;
}
