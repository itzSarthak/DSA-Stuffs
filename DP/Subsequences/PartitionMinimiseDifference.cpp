#include <bits/stdc++.h>
using namespace std;

// DP : 16
// Prob : Return minimum difference of absolute sum of two subsets from a given array**
// We have a non negative array here ** 


// Memoization **
bool SumPossible(int idx,int target,vector<int>& arr,vector<vector<int>>& dp)
{
    // base case 

    // target zero somwhere or we have reached at the end **
    if(target == 0) return true;
    if(idx == 0) return (target == arr[0]);

    // already computed ??
    if(dp[idx][target] != -1) return dp[idx][target];

    // otherwise 
    bool non_pick = SumPossible(idx - 1,target,arr,dp);

    bool pick = false;
    if(target >= arr[idx])
        pick = SumPossible(idx - 1,target - arr[idx],arr,dp);

    dp[idx][target] = pick | non_pick;
    return dp[idx][target];
}
int minSubsetSumDifference(vector<int>& arr, int n)
{
    int total_sum = 0;
    for(int x : arr)
        total_sum += x;

    vector<vector<int>> dp(n,vector<int>(total_sum+1,-1));

    int mini = 1e9;

    for(int s1 = 0; s1 <= total_sum; s1++)
    {
        if(SumPossible(n-1, s1, arr, dp))
        {
            int diff = abs(total_sum - 2*s1);
            mini = min(mini, diff);
        }
    }

    return mini;
}


// Tabulation **
int minSubsetSumDifference(vector<int>& arr, int n)
{
    // in our subset sum problem we had a 2d dp array which tells weather a particular sum possible till idx
    // S1 (first partitioned sum) : [0,total_sum]

    int total_sum = 0;
    for(int i = 0; i < n; i++)
        total_sum+=arr[i];

    vector<vector<bool>>dp (n,vector<bool>(total_sum + 1,false));

    for(int i = 0; i < n; i++) 
        dp[i][0] = true;

    if(arr[0] <= total_sum) 
        dp[0][arr[0]] = true;

    for(int i = 1; i < n; i++)
    {
        for(int tg = 1; tg <= total_sum;tg++ )
        {
            // Exclude the current element
            bool notTaken = dp[i - 1][tg];

            // Include the current element if it doesn't exceed the target
            bool taken = false;
            if (arr[i] <= tg)
                taken = dp[i - 1][tg - arr[i]];

            dp[i][tg] = notTaken || taken;
        }
    }


    // now we have a dp array which will tells weather a particular subset sum exists in the array
    // we only need to care about the last row since that represent till last element in the array

    int mini = 1e9;
    for(int tg = 0; tg <= total_sum; tg++)
    {
        if(dp[n - 1][tg])
            mini = min(mini,abs(total_sum - 2*tg));
    }
    


}




// DP : 18
// Prob : Count Partition with given difference 
// S1 - S2 = D
// This changes to finding total subset having sum equals (total_sum - diff)/2
// Edge cases : (total_sum - diff) must be even and positive **


// Memoization**
int solve(int idx,int target,vector<int>&arr,vector<vector<int>>dp)
{
    // base case : 
    if(target == 0) return 1;
    if(idx == 0) return (target == arr[0] ? 1 : 0);


    if(dp[idx][target] != -1) return dp[idx][target];


    int no_pick = solve(idx - 1,target,arr,dp);
    int pick = 0;
    if(arr[idx] <= target)
        pick = solve(idx-1,target - arr[idx],arr,dp);

    return pick + no_pick;
}
int countPartitions(int n, int diff, vector<int>& arr)
{
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum+= arr[i];

    if((totalSum - diff)%2) return -1;
    int target = (totalSum - diff)/2;


    vector<vector<int>>dp(n,vector<int>(target+1,-1));
    return solve(n - 1,target,arr,dp);
}


// Tabulation **
int countPartitions(int n, int diff, vector<int>& arr)
{
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum+= arr[i];

    if((totalSum - diff)%2) return -1;
    int target = (totalSum - diff)/2;


    vector<vector<int>>dp(n,vector<int>(target+1,0));
    
    // base case : target is zero & idx is zero 
    for(int i = 0; i < n; i++) dp[i][0] = 1;

    if(arr[0] <= target)
        dp[0][arr[0]] = 1;

    
    // otherwise
    for(int i = 1; i < n; i++)
    {
        for(int tg = 0; tg <= target; tg++)
        {
            int no_pick = dp[i - 1][tg];
            int pick = 0;
            if(arr[i] <= tg)
                pick = dp[i - 1][tg - arr[i]];

            dp[i][tg] = pick + no_pick;
        }
    }

    return dp[n - 1][target];


}


int main()
{
    return 0;
}
