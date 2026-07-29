#include <bits/stdc++.h>
using namespace std;

// Memoization **
int solve(int idx1,int idx2,string& s1,string& s2,vector<vector<int>>& dp)
{
    // base case
    if(idx1 < 0 || idx2 < 0) return 0;

    if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

    if(s1[idx1] == s2[idx2])
        return dp[idx1][idx2] = 1 + solve(idx1 - 1,idx2 - 1,s1,s2,dp);

    
    return dp[idx1][idx2] = max(solve(idx1 - 1,idx2,s1,s2,dp),solve(idx1,idx2 - 1,s1,s2,dp));
}
int longestPalindromeSubseq(string s)
{
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(),s2.end());

    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    return solve(n - 1,m - 1,s1,s2,dp);
}



// Tabulation **
int lcs(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();

    // Here we do shifting to accomodated base case from memoization **
    vector<vector<int>>dp(n + 1,vector<int>(m + 1,-1));

    // Here we do shifting to accomodated base case from memoization **
    // basically idx1 & idx2 of this is right shifted version of idx1,idx2 of memoization **
    // idx - 1 : idx(memoiz)

    // base case **
    for(int idx1 = 0; idx1 <= n; idx1++)
        dp[idx1][0] = 0;

    for(int idx2 = 0; idx2 <= m; idx2++)
        dp[0][idx2] = 0;


    for(int idx1 = 1; idx1 <= n; idx1++)
    {
        for(int idx2 = 1; idx2 <= m; idx2++)
        {
            if(s1[idx1 - 1] == s2[idx2 - 1])
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                // here idx1 & idx2 in the dp array corresponds to idx - 1th index of str

            else
                dp[idx1][idx2] = max(dp[idx1 - 1][idx2],dp[idx1][idx2 - 1]);
        }
    }

    return dp[n][m];

}
int minInsertions(string s)
{
    string s1 = s;
    string s2 = s;
    reverse(s2.begin(),s2.end());


    return s.size() - lcs(s1,s2);
}