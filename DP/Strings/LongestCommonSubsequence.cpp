#include <bits/stdc++.h>
using namespace std;

// DP : 25
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
int lcs(string s1,string s2)
{
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    return solve(n - 1,m - 1,s1,s2,dp);
}

// Tabulation **
int plcs(string s1,string s2)
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


// DP : 26
// Here we need to print this lcs **
string printlcs(string s1,string s2)
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

    int len = dp[n][m];
    string str = "";
    for(int i = 0; i < len; i++)
        str+="$";

    int idx = len - 1;


    // now we are going to use that dp array to print our string **
    // we are starting from corner if matches 
    // include in our final str otherwise return none **
    int i = n,j = m;
    while(i > 0 && j > 0)
    {
        if(s1[i - 1] == s2[j - 1])
        {
            str[idx--] = s1[i - 1];
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;

        else    
            i--;
    }

    return str;

}



// DP : 27
// Longest Common Substring

// Using the same Subseq pattern only we change the recurrence relation a little bit
// Tabulation **
int lcsubstr(string s1,string s2)
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

    int ans = 0;
    for(int idx1 = 1; idx1 <= n; idx1++)
    {
        for(int idx2 = 1; idx2 <= m; idx2++)
        {
            if(s1[idx1 - 1] == s2[idx2 - 1])
            {
                dp[idx1][idx2] = 1 + dp[idx1 - 1][idx2 - 1];
                ans = max(ans,dp[idx1][idx2]);
            }
                // here idx1 & idx2 in the dp array corresponds to idx - 1th index of str

            else
                // dp[idx1][idx2] = max(dp[idx1 - 1][idx2],dp[idx1][idx2 - 1]);
                dp[idx1][idx2] = 0;

        }
    }

    return ans;

}

int main()
{
    string x = "";
    // cout<<x<<" "<<y<<" "<<z<<endl;
    cout<<x.size();
    return 0;
}