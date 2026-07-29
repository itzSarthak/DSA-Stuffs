#include <bits/stdc++.h>
using namespace std;


// Memoization **
int solve(int idx,int l,vector<int>& price,vector<vector<int>>& dp)
{
    if(idx == 0)
        return l * price[0];

    if(dp[idx][l] != -1) return dp[idx][l];

    int noTake = solve(idx - 1,l,price,dp);
    int take = INT_MIN;

    // idx + 1 represents rod length of picked part **
    int rodlength = idx + 1;
    if(rodlength <= l)
        take = price[idx] + solve(idx,l - rodlength,price,dp);

    return  dp[idx][l] = max(take,noTake);
}
int rodCutting(vector<int> price, int n)
{
    vector<vector<int>>dp(n,vector<int>(n + 1,-1));
    return solve(n - 1,n,price,dp);
}


// Tabulation **
int rodCutting(vector<int> price, int n)
{
    vector<vector<int>>dp(n,vector<int>(n + 1,0));
    
    // base case **
    for(int l = 0; l <= n; l++)
        dp[0][l] =  l * price[0];


    for(int idx = 1; idx < n; idx++)
    {
        for(int l = 1; l <= n; l++)
        {
            int noTake = dp[idx - 1][l];
            int take = INT_MIN;

            int rodlength = idx + 1;
            if(rodlength <= l)
                take = price[idx] + dp[idx][l - rodlength];
        }
    }

    
}

int main()
{
    return 0;
}