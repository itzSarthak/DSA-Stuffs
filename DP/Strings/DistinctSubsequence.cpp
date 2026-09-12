#include <bits/stdc++.h>
using namespace std;

// Memoization **
int solve(int i,int j,string& s,string& t,vector<vector<int>>& dp)
{
    // base case
    if(j < 0) return 1;
    if(i < 0) return 0;


    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j])
        return dp[i][j] = solve(i - 1,j - 1,s,t,dp) + solve(i - 1,j,s,t,dp);

    else
        return dp[i][j] = solve(i - 1,j,s,t,dp);
}
int numDistinct(string s, string t)
{
    vector<vector<int>>dp(s.size(),vector<int>(t.size(), -1));
    return solve(s.size() - 1,t.size() - 1,s,t,dp);
}


// Tabulation
int numDistinct(string s, string t)
{
    vector<vector<double>>dp(s.size() + 1,vector<double>(t.size() + 1, 0));
    
    int n = s.size();
    int m = t.size();
    
    // base case
    // Case : t exhausted 
    for(int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // Case : s exhausted ( we don't need this since dp intialise to zero)
    // j starts from 1 here since we can't override dp[0][0]
    // for(int j = 0; j <= m; j++)
    //     dp[0][j] = 0;

    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    // dp[i][j] : for t of length j how may t exists in s having length i
    return (int)dp[n][m];

}

int main()
{
    return 0;
}
