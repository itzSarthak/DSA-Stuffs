#include <bits/stdc++.h>
using namespace std;


// DP 14
// Problem 1: Return weather a subset having sum equals target exists or not **

// Memoization**
// we start this from sovle(n-1,target) --> weather subset sum target exists till n-1 
bool solve(int idx,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    // base case 

    // target zero somwhere or we have reached at the end **
    if(target == 0) return true;
    if(idx == 0) return (target == arr[0]);

    // already computed ??
    if(dp[idx][target] != -1) return dp[idx][target];

    // otherwise 
    bool non_pick = solve(idx - 1,target,arr,dp);

    bool pick = false;
    if(target >= arr[idx])
        pick = solve(idx - 1,target - arr[idx],arr,dp);

    dp[idx][target] = pick | non_pick;
    return dp[idx][target];
}
bool isSubsetSum(vector<int>arr, int target)
{
    // Since from tree diagram subproblem exists 
    // dp[idx][target]
    // n given [1,100]

    // idx : [0,99]
    // target : [0,5000]


    // what does this dp represents **
    // dp[idx][target] represents weather there exists a subset sum till idx (from zero) equals to target **

    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(target,-1));
    return solve(n - 1,target,arr,dp);
}


// Tabulation **
bool isSubsetSum(vector<int>arr, int target)
{
    // Since from tree diagram subproblem exists 
    // dp[idx][target]
    // n given [1,100]
    // idx : [0,99]
    // target : [0,5000]


    // what does this dp represents **
    // dp[idx][target] represents weather there exists a subsequences sum till idx (from zero) equals to target **

    int n = arr.size();
    vector<vector<bool>>dp(n,vector<bool>(target + 1,false));
    

    // target zero -- case (base)
    for(int i = 0; i < n; i++)
        dp[i][0] = true;

    // index zero -- case (base)
    if(arr[0] <= target)
        dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++)
    {
        for(int tg = 0; tg <= target; tg++)
        {
            // dp[i][target] = dp[i - 1][target] || dp[i - 1][target - arr[i]];

            bool no_pick = dp[i - 1][tg];

            bool pick = false;
            if(tg >= arr[i])
                pick = dp[i - 1][tg - arr[i]];

            dp[i][tg] = pick || no_pick;
        }
    }

    return dp[n - 1][target];
}



// Problem 2: Return total number of subsets having sum equals target **,m 
// DP : 17

// Memoization **
int solveSubsetSum(int idx,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    // base case 

    // target zero somwhere or we have reached at the end **
    if(target == 0) return 1;
    if(idx == 0) return (target == arr[0] ? 1 : 0);

    // already computed ??
    if(dp[idx][target] != -1) return dp[idx][target];

    // otherwise 
    int non_pick = solveSubsetSum(idx - 1,target,arr,dp);

    int pick = 0;
    if(target >= arr[idx])
        pick = solveSubsetSum(idx - 1,target - arr[idx],arr,dp);

    dp[idx][target] = pick + non_pick;
    return dp[idx][target];
}
int countSubsetSum(vector<int>arr, int target)
{
    // Since from tree diagram subproblem exists 
    // dp[idx][target]
    // n given [1,100]

    // idx : [0,99]
    // target : [0,5000]


    // what does this dp represents **
    // dp[idx][target] represents weather there exists a subsequences sum till idx (from zero) equals to target **

    int n = arr.size();

    vector<vector<int>>dp(n,vector<int>(target,-1));
    return solve(n - 1,target,arr,dp);
}

// Tabulation **
int TabulationisSubsetSum(vector<int>arr, int target)
{

    // what does this dp represents **
    // dp[idx][target] represents how many subsequences sum till idx (from zero) equals to target **

    int n = arr.size();
    vector<vector<int>>dp(n,vector<int>(target + 1,0));

    // target zero -- case (base)
    for(int i = 0; i < n; i++)
        dp[i][0] = 1;

    // index zero -- case (base)
    if(arr[0] <= target)
        dp[0][arr[0]] = 1;

    for(int i = 1; i < n; i++)
    {
        for(int tg = 0; tg <= target; tg++)
        {
            // dp[i][target] = dp[i - 1][target] || dp[i - 1][target - arr[i]];

            int no_pick = dp[i - 1][tg];

            int pick = false;
            if(tg >= arr[i])
                pick = dp[i - 1][tg - arr[i]];

            dp[i][tg] = pick + no_pick;
        }
    }

    return dp[n - 1][target];
}



// Change the code when there are zeros allowed in the array **

int main ()
{
    return 0;
}