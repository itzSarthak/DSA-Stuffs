#include <bits/stdc++.h>
using namespace std;

// Problem : 
/*
    A frog wants to climb a staircase with n steps. 
    Given an integer array heights, where heights[i] contains the height of the ith step.

    To jump from the ith step to the jth step, 
    the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference.
    The frog can jump from any step either one or two steps, provided it exists.

    Example 1
    Input: heights = [2, 1, 3, 5, 4]
    Output: 2

    Explanation:
    One possible route can be,
    0th step -> 2nd Step = abs(2 - 3) = 1
    2nd step -> 4th step = abs(3 - 4) = 1
    Total = 1 + 1 = 2.

    Example 2
    Input: heights = [7, 5, 1, 2, 6]
    Output: 9

    Explanation:
    One possible route can be,
    0th step -> 1st Step = abs(7 - 5) = 2
    1st step -> 3rd step = abs(5 - 2) = 3
    3rd step -> 4th step = abs(2 - 6) = 4
    Total = 2 + 3 + 4 = 9.

    Return the minimum amount of energy required 
    by the frog to go from the 0th step to the (n-1)th step.
*/

// Memoization **
int first_sol(int idx,vector<int>& heights,vector<int>& dp)
{                     // step 1 : create a dp array **
    
    // base case **
    if(idx == 0) return 0;

    // step 3 : Already computed ??
    if (dp[idx] != -1) return dp[idx];

    // otherwise

    // option first
    int left_rec = first_sol(idx - 1,heights,dp) + abs(heights[idx] - heights[idx - 1]);

    // option second
    int right_rec = INT_MAX;
    if(idx > 1)
        right_rec = first_sol(idx - 2,heights,dp) + abs(heights[idx] - heights[idx - 2]);

    // step 2 (storing the answer and returning it)
    dp[idx] = min(left_rec,right_rec);
    return dp[idx];
}


// Tabulation **
int second_sol(vector<int>& heights,vector<int>& dp,int n)
{
    // step 1 : dp array

    // step 2 : base case
    dp[0] = 0;

    // step 3 : iterate and return
    for(int i = 1; i < n; i++)
    {
        int fs = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        
        int ss = INT_MAX;
        if(i > 1) ss = dp[i - 2] + abs(heights[i] - heights[i - 2]);

        dp[i] = min(fs,ss);
    }

    return dp[n - 1];
    
}


// Space Optimization **
int third_sol(vector<int>& heights,int n)
{
    int prev,last_prev,curr;
    prev = last_prev = 0;

    for(int i = 1; i < n; i++)
    {
        int fs = prev + abs(heights[i] - heights[i - 1]);

        int ss = INT_MAX;
            if(i > 1) ss = last_prev + abs(heights[i] - heights[i - 2]);

        curr = min(prev,last_prev);

        last_prev = prev;
        prev = curr;

    }

    return prev;
}


int main()
{


    return 0;
}
