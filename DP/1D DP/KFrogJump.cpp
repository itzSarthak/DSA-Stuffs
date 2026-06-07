#include <bits/stdc++.h>
using namespace std;

// Problem : 
/*
    A frog wants to climb a staircase with n steps.
    Given an integer array heights, where heights[i] contains the height of the ith step, 
    and an integer k. To jump from the ith step to the jth step,
    the frog requires abs(heights[i] - heights[j]) energy,
    where abs() denotes the absolute difference.
    The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists.
    Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.


    Example 1:
    Input: heights = [10, 5, 20, 0, 15], k = 2
    Output: 15
    Explanation:
    0th step -> 2nd step, cost = abs(10 - 20) = 10
    2nd step -> 4th step, cost = abs(20 - 15) = 5
    Total cost = 10 + 5 = 15.

    Example 2:
    Input: heights = [15, 4, 1, 14, 15], k = 3
    Output: 2
    Explanation:
    0th step -> 3rd step, cost = abs(15 - 14) = 1
    3rd step -> 4th step, cost = abs(14 - 15) = 1
    Total cost = 1 + 1 = 2.
*/


// Memoization
int first_sol(int idx,int k,vector<int>& dp,vector<int>& heights)
{
    // base case: 
    if(idx == 0) return 0;

    // Already calculated **
    if(dp[idx] != -1) return dp[idx];

    // frog have k options
    int ans = INT_MAX;
    for(int i = 1; i <= k; i++)
    {
        if(idx - i >= 0)
        {
            int jump = first_sol(idx - i,k,dp,heights) + (heights[idx] - heights[idx - i]);
            ans = min(ans,jump);
        }
    }

    dp[idx] = ans;
    return dp[idx];
}


// Tabulation
int second_sol(int n,int k,vector<int>& dp,vector<int>& heights)
{
    dp[0] = 0;
    

    for(int i = 1; i < n; i++)
    {
        int ans = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i - j >= 0)
            {
                int jump = dp[i - j] + abs(heights[i] - heights[i - j]);
                ans = min(ans,jump);
            }
        }

        dp[i] = ans;
    }

    return dp[n - 1];
}

int main()
{
    return 0;
}
