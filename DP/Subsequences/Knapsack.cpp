#include <bits/stdc++.h>
using namespace std;


// Prob : 
// Given weight and values two array 
// A thief having fixed wieght 'W' 

// Maximum values a thief can stole within the limit of his bag (W) **
// He can stole one item only once **

// DP : 19 (0/1 Knapsack)
// Memoization **
int solve(int idx,int w,vector<int> &values, vector<int> &weights,vector<vector<int>>& dp)
{
    /*
        Here idx : n - 1 to 0
        w : w(given) to 0

        these two are only variables 
        since we find that subproblem exists we now use memoization **
        dp[i][w] maximum values the thief can have with weight(w) till ith item (starts from zero)
    */
    if(idx == 0)
    {
        if(weights[0] <= w) return values[0];
        
        return 0;
    }

    if(dp[idx][w] != -1) return dp[idx][w];

    int not_pick = solve(idx - 1,w,values,weights,dp);
    int pick = INT_MIN;
    
    if(weights[idx] <= w)
        pick = values[idx] + solve(idx - 1,w - weights[idx],values,weights,dp);

    return dp[idx][w] = max(not_pick,pick);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// n : total no of items (size of values)
    // w : fixed weight (limit of thief bag)
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return solve(n - 1,w,values,weights,dp);
}


// Tabulation **
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// n : total no of items (size of values)
    // w : fixed weight (limit of thief bag)

    vector<vector<int>>dp(n,vector<int>(w+1,0));
    // dp[i][w] maximum values the thief can have with weight(w) till ith item (starts from zero)

    
    // base case 
    for(int i = 0; i <= w; i++)
    {
        if(weights[0] <= i)
            dp[0][i] = values[0];
    }


    // otherwise **
    for(int i = 1; i < n; i++)
    {
        for(int wt = 0; wt <= w; wt++)
        {
            int not_pick = dp[i - 1][wt];
            int pick = INT_MIN;
    
            if(weights[i] <= wt)
                pick = values[i] + dp[i - 1][wt - weights[i]];

            dp[i][wt] = max(pick,not_pick);
        }
    }

    return dp[n - 1][w];
}


// Space Optimization **
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// n : total no of items (size of values)
    // w : fixed weight (limit of thief bag)

    vector<int>prev(w + 1,0);
    vector<int>curr(w + 1,0);

    // these two represents prev state and current state for us **

    
    // base case 
    for(int i = 0; i <= w; i++)
    {
        if(weights[0] <= i)
            prev[i] = values[0];
    }


    // otherwise **
    for(int i = 1; i < n; i++)
    {
        for(int wt = 0; wt <= w; wt++)
        {
            int not_pick = prev[wt];
            int pick = INT_MIN;
    
            if(weights[i] <= wt)
                pick = values[i] + prev[wt - weights[i]];

            curr[wt] = max(pick,not_pick);
        }
        prev = curr;
    }

    return prev[w];
}


// Space Optimization II **
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// n : total no of items (size of values)
    // w : fixed weight (limit of thief bag)

    vector<int>prev(w + 1,0);
    vector<int>curr(w + 1,0);

    // these two represents prev state and current state for us **

    
    // base case 
    for(int i = 0; i <= w; i++)
    {
        if(weights[0] <= i)
            prev[i] = values[0];
    }


    // otherwise **
    for(int i = 1; i < n; i++)
    {
        // reversing this doesn't change anything since we are depending upon prev rows **
        for(int wt = w; wt >= 0; wt--)
        {
            int not_pick = prev[wt];
            int pick = INT_MIN;
    
            if(wt <= w)
                pick = values[i] + prev[wt];

            // curr[wt] = max(pick,not_pick);
            // since we are using left side prev array elements to fill the curr array
            //  we can override the same prev element only
            prev[wt] = max(pick,not_pick);

        }
    }

    return prev[w];
}
