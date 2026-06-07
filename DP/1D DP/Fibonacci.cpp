#include <bits/stdc++.h>
using namespace std;

// Fibonacci using DP **

// Memoization
int fib_memoization(int n,vector<int>& dp)
{
    if(n <= 1)
        return n;


    // if alredy computed **
    if(dp[n] != -1) return dp[n];

    // otherwise compute and update dp array **
    dp[n] = fib_memoization(n - 1,dp) + fib_memoization(n - 2,dp);
    return dp[n];
}

// Tabulation
int fib_tabulation(int n)
{

    if (n == 0) return 0;
    if (n == 1) return 1;

    vector<int> dp(n + 1);

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Build the table
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// Further optimization to O(1) space complexity **
int fib(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0; // F(n-2)
    int prev1 = 1; // F(n-1)
    int curr;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2; // F(n)
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    // Steps to convert the prob into DP (Memoization **)

    // 1 > Create a dp array 

    // 2 > Store subproblem result into it 

    // 3 > Avoid recomputing if result already present otherwise compute and update the DP Array


    int n; cin >> n;
    vector<int>dp(n+1,-1);

    cout<<fib_memoization(n,dp);
    // TC : O(n)  SC : O(n) -- recursion stack as well of size n


    cout<<fib_tabulation(n);
    // TC : O(n)  SC : O(n)


    cout<<fib(n);
    // TC : O(n)  SC : O(1)


    // this can be further optimized with three varables to have space complexity of O(1) **


    return 0;
}
