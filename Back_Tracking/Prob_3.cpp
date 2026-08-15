
#include <bits/stdc++.h>
using namespace std;
/*
    ** 1. Combination Sum I
    ** 2. Combination Sum II
*/
// Prob_1
void a_combinations(int id,vector<int>&arr,int target,vector<int>&ds,vector<vector<int>>&ans)
{
        // Base Case
        if(id == arr.size())
        {
            if(target == 0)
                ans.push_back(ds);
            return;
        }

        // Pick and Remain at the index
        if(arr[id] <= target)
        {
            ds.push_back(arr[id]);
            a_combinations(id,arr,target-arr[id],ds,ans);        
            ds.pop_back();
        }

        // Not Pick and Move to next index
        a_combinations(id + 1,arr,target,ds,ans);


        // Time Complexity : O(2^t * k)
        // Space Complexity : O(k * x)
        // In this case Time complexity depends upon target !
}

// Prob_2
void solve(int ind,int target,vector<int>&ds,vector<vector<int>>&res,vector<int>&arr)
    {
        if(target == 0)
        {
            res.push_back(ds);
            return;
        }

        //  since we need to return unique answer
        //  we should go with a loop    

        for(int i = ind; i < arr.size(); i++)
        {
            if(i > ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            
            ds.push_back(arr[i]);
            solve(i+1,target-arr[i],ds,res,arr);
            ds.pop_back();
        }
            /*
        Time Complexity : O(2^n * k)
        Space Complexity : O(k * x)
            */
    }

int main()
{
    return 0;
}