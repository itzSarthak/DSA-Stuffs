#include<bits/stdc++.h>
using namespace std;
    

// Memoization **
// We moved from f(m - 1,n -1) to f(0,0)
// here dp[i][j] represents minimum sum from (i,j) to (0,0)

// TC : O(n*n)
// SC : O(n*n) + O(n)

int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid)
{
    // Top Bottom Approach - (Target to Source)
    if(i == 0 && j == 0) return grid[0][0];
    if(i < 0 || j < 0) return 1e9;
    // if(i < 0 || j < 0) return INT_MAX;
    // never do arithmatic operrations with boundary values overflow is inevitable **


    // Already Computed **
    if(dp[i][j] != -1)
        return dp[i][j];

    int x = grid[i][j] + solve(i - 1,j,dp,grid);

    int y = grid[i][j] + solve(i,j - 1,dp,grid);

    dp[i][j] = min(x , y);
    return dp[i][j];
}
int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(m - 1,n - 1,dp,grid);
}


// Tabulation **
// TC : O(n*n)
// SC : O(n*n)  
// Recursion stack space saved here ** 

int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>>dp(m,vector<int>(n,0));


    // Base Case **
    dp[0][0] = grid[0][0];

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0) continue;

            int up = 1e9;
            int left = 1e9;

            if(i >= 1)
                up = grid[i][j] + dp[i - 1][j];
            
            if(j >= 1)
                left = grid[i][j] + dp[i][j - 1];

            dp[i][j] = min(up,left);
        }
    }

    return dp[m - 1][n - 1];

}


// Space Optimization **
int minPathSum(vector<vector<int>>& grid)
{
    int m = grid.size();
    int n = grid[0].size();

    // vector<vector<int>>dp(m,vector<int>(n,0));
    vector<int>prev(n,0);
    


    // Base Case **
    // dp[0][0] = grid[0][0];

    // This prev array stores minimum sum till (i,j) from (0,0)
    prev[0] = grid[0][0];

    for(int i = 0; i < m; i++)
    {
        vector<int>curr(n,0);
        for(int j = 0; j < n; j++)
        {
            // do not forget to updated curr[0]
            if(i == 0 && j == 0)
            {
                curr[j] = grid[0][0];
                continue;
            }

            int up = 1e9;
            int left = 1e9;

            if(i >= 1)
                // up = grid[i][j] + dp[i - 1][j];
                up = grid[i][j] + prev[j];

            
            if(j >= 1)
                // left = grid[i][j] + dp[i][j - 1];
                left = grid[i][j] + curr[j - 1];


            curr[j] = min(up,left);
        }

        prev = curr;
    }

    // return dp[m - 1][n - 1];
    return prev[n - 1];

}
