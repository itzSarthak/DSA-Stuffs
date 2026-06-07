#include <bits/stdc++.h>
using namespace std;

// Memoization **
int solve(int n,vector<int>& dp)
{
    // base case: 
    if(n <= 1) return 1;

    // otherwise
    if(dp[n] != -1) return dp[n];

    dp[n] = solve(n - 1,dp) + solve(n - 2,dp);
    return dp[n];
}

// Tabulation **
int solve(int n)
{
    vector<int>dp(n+1);
    dp[0] = dp[1] = 1;

    for(int i = 2; i < n+1; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];


}

// Most Optimized **
int solve(int n)
{
    if(n <= 1)
        return 1;

    int f_approach = 1;
    int s_approach = 1;

    for(int i = 2; i < n+1; i++)
    {
        int curr = f_approach + s_approach;
        f_approach = s_approach;
        s_approach = curr;
    }

    return s_approach;
}

int main()
{
    // Very similar to that of Fibonacci this can also be solved
    // using three methods **


    return 0;
}
