#include <bits/stdc++.h>
using namespace std;
/*
    ** 1. Subset Sum I
    ** 2. Subset Sum II
*/
// prob_1
    void solve(int id,int sum,vector<int>&res,vector<int>&arr,int N)
    {
        // Base
        if(id == N)
        {
            res.push_back(sum);
            return;
        }

        // 1. Not Pick
        solve(id+1,sum,res,arr,N);
        // 2. Pick
        solve(id+1,sum+arr[id],res,arr,N);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>res;
        solve(0,0,res,arr,N);
        sort(res.begin(),res.end());
        return res;
    }
    /*
        ** Total no of subsets : 2^n
        ** Depth of the function : n
        ** Time Complexity : O(2^n) + klogk  (where k = 2^n)
        ** Space Complexity : O(2^n)
    */


// prob_2
void solve(vector<int>&ds,int id,vector<vector<int>>&res,vector<int>&nums)
{
    res.push_back(ds);
    for(int i = id; i < nums.size(); i++)
    {
        if(i != id && nums[i] == nums[i-1]) continue;
        // there are no need to take duplicates.

        ds.push_back(nums[i]);
        solve(ds,i+1,res,nums);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    vector<vector<int>>res;
    vector<int>ds;
    int id = 0;
    sort(nums.begin(),nums.end());

    solve(ds,id,res,nums);  
    return res;      
}
/*
    ** Insted of Pick and Non - Pick
    ** We need to have a loop to pick element for 
        a particualr size subset.

    ** Here we are moving from 

    ** empty subset
        |
    ** size 1 subset
        |
    ** size 2 subset
        |
    ** size 3 subset
        |
    ** size 4 subset
        |
    ** ans so on....

    ** for each size s 
        with the help of loop we can insert new element.
*/